public class Parser {

    // need a symbol table
    private Symtab symtab = new Symtab();

    // the first sets.
    // note: we cheat sometimes:
    // when there is only a single token in the set,
    // we generally just compare tkrep with the first token.
    TK f_declaration[] = {TK.VAR, TK.CONST, TK.none};
    TK f_var_decl[] = {TK.VAR, TK.none};
    TK f_const_decl[] = {TK.CONST, TK.none};
    TK f_statement[] = {TK.ID, TK.PRINT, TK.IF, TK.WHILE, TK.FOR, TK.REPEAT, TK.none};
    TK f_print[] = {TK.PRINT, TK.none};
    TK f_assignment[] = {TK.ID, TK.none};
    TK f_if[] = {TK.IF, TK.none};
    TK f_while[] = {TK.WHILE, TK.none};
    TK f_for[] = {TK.FOR, TK.none};
    TK f_expression[] = {TK.ID, TK.NUM, TK.LPAREN, TK.none};
    TK f_string[] = {TK.STRING, TK.none};
    TK f_repeat[] = {TK.REPEAT, TK.none};

    // tok is global to all these parsing methods;
    // scan just calls the scanner's scan method and saves the result in tok.
    private Token tok; // the current token
    private void scan() {
        tok = scanner.scan();
    }

    private Scan scanner;
    Parser(Scan scanner) {
        this.scanner = scanner;
        scan();
        program();
        if( tok.kind != TK.EOF )
            parse_error("junk after logical end of program");
    }

    // for code generation
    private static final int initialValueEVariable = 8888;
    private static final int initialValueEArray = 4444;

    // print something in the generated code
    private void gcprint(String str) {
        System.out.println(str);
    }
    // print identifier in the generated code
    // it prefixes x_ in case id conflicts with C keyword.
    private void gcprintid(String str) {
        System.out.println("x_"+str);
    }
    private void gcprintarr(String str, int i) {
        System.out.println("x_"+str+"["+i+"]");
    }

    private void program() {
        gcprint("#include <stdio.h>");
	gcprint("#include <stdlib.h>");
	gcprint("int bc(char s[], int lno, int lb, int ub, int exp) {");
	gcprint("if (exp < lb || exp > ub) {");
	gcprint("fprintf(stderr, \"subscript (%d) out of bounds for array %s[%d:%d] on line %d\\n\", exp, s, lb, ub, lno);");
	gcprint("exit(1);");
	gcprint("} else {");
	gcprint("return exp;");
	gcprint("}}");
        gcprint("main() ");
        block();
    }

    private void block() {
        gcprint("{");
        symtab.begin_st_block();
        while( first(f_declaration) ) {
            declaration();
        }
        while( first(f_statement) ) {
            statement();
        }
        symtab.end_st_block();
        gcprint("}");
     }

    private void declaration() {
        if (first(f_var_decl)) {
            var_decl();
        }
        else if (first(f_const_decl)) {
            const_decl();
        }
        else
            parse_error("oops -- declaration bad first");
    }

    private void var_decl() {
		  mustbe(TK.VAR);
        decl_id();
        while( is(TK.COMMA) ) {
            scan();
            decl_id();
        }
    }
    
    private void decl_id() {
    	if ( is(TK.ID) ) {
    		Token temp = tok;
    		scan();
    		if ( is(TK.LBRACKET) ) {
    			scan();
				int lb = bound();//true => lower bound
				mustbe(TK.COLON);
				int ub = bound();//false => upper bound
				mustbe(TK.RBRACKET);//need to know size / offset by here... // scan here
				var_decl_arr(temp, lb, ub);
    		}
    		else
    			var_decl_id(temp);
    	}
    	else {
            parse_error("expected id in var declaration, got " + tok);
        }
    	// already scans at end
    }

	
    private void var_decl_id(Token temp) {
        if (symtab.add_entry(temp.string, temp.lineNumber, TK.VAR)) {
        	gcprint("int ");
            gcprintid(temp.string);
            gcprint("="+initialValueEVariable+";");
        }
        //scan();
    }

	// public boolean add_entry(String myid, int myline, TK myVarOrConst)

    
    private void var_decl_arr(Token t, int lb, int ub) {
    	int size = ub - lb + 1;
    	int offset = lb;
    	if (size <= 0) {
    		System.err.println("declared size of "+ t.string + " is <= 0 ("+ size +") on line "
                    + t.lineNumber);
    		System.exit(1);
    	}
    	if (symtab.add_entry(t.string, t.lineNumber, TK.ARRAY, offset, size)) {
    		gcprint("int ");
            gcprintarr(t.string, size); // prints x_(id)[size]
            // initialize array:
            String initializer = "";
            for (int i=0; i<size; i++)
            	initializer += (initialValueEArray + ", ");
            initializer = "{" + initializer + "}";
            gcprint("="+initializer+";");
    	}
    	//scan();
    }

	 private int bound(){
		 int ret = -1; // -1 means error in retrieving the bound from input somehow
		int multiplyBy = 1;
		if( is (TK.MINUS) ) {
			multiplyBy = -1;
			scan();
		}
		mustbeNoScan(TK.NUM);
		if ( is(TK.NUM) ) { // should always be the case due to mustbeNoScan
			ret = multiplyBy * Integer.parseInt(tok.string);
		}
		scan();
		return ret;
	}

    private void const_decl() {
        mustbe(TK.CONST);
        boolean newConst = const_decl_id();
        mustbe(TK.EQ);
        if (newConst) {
            gcprint("=");
            gcprint(tok.string);
            gcprint(";");
        }
        mustbe(TK.NUM);
    }

    private boolean const_decl_id() {
        if( is(TK.ID) ) {
            boolean ret;
            if (ret = symtab.add_entry(tok.string, tok.lineNumber, TK.CONST)) {
                gcprint("int ");
                gcprintid(tok.string);
            }
            scan();
            return ret;
        }
        else {
            parse_error("expected id in const declaration, got " + tok);
            return false; // meaningless since parse_error doesn't return
        }
    }

    private void statement(){
        if( first(f_assignment) )
            assignment();
        else if( first(f_print) )
            print();
        else if( first(f_if) )
            ifproc();
        else if( first(f_while) )
            whileproc();
        else if( first(f_for) )
            forproc();
	else if( first(f_repeat) )
	    repeat();
        else
            parse_error("oops -- statement bad first");
    }

    private void assignment(){
        if( is(TK.ID) ) {
            //lvalue_id(tok.string, tok.lineNumber);
            //scan();
        	id_sub(); // need to scan at end of this function or after
        }
        else {
            parse_error("missing id on left-hand-side of assignment");
        }
        mustbe(TK.ASSIGN);
        gcprint("=");
        expression();
        gcprint(";");
    }
    
    private void id_sub(){
    	Token temp = tok; // save current token
    	scan(); // scan here so don't scan at end
    	if ( is(TK.LBRACKET) ) {
    		scan(); // get past '['
    		Entry e = lvalue_array(temp.string, temp.lineNumber);
    		gcprint("x_"+temp.string+"[(-1)*"+e.getArrayOffset()+"+");
    		//expression();
		bc(temp, e.getArrayOffset(), e.getArraySize());
    		mustbe(TK.RBRACKET);
    		gcprint("]");
    	}
    	else {
    		lvalue_id(temp.string, temp.lineNumber);
    	}
    }

    private void bc (Token t, int offset, int size) {
	int lb = offset;
	int ub = offset + size - 1;
	gcprint("bc(\""+t.string+"\", "+t.lineNumber+", "+lb+", "+ub+",");
	expression();
	gcprint(")");
    }

    private void print(){ // printf( "%d\n", 3); || printf( "%s\n", "asdsa");
        mustbe(TK.PRINT);
        gcprint("printf(");
        print_expression();
        gcprint(");");
    }

    private void print_expression(){
	if ( first(f_expression) ) {
		gcprint("\"%d\\n\", ");
		expression();
	} else if (first(f_string)) {
		gcprint("\"%s\\n\", ");
		gcprint(tok.string);
		scan();
	} else
		System.exit(1);//parse_error("oops -- print_expression bad first");
    }

    private void ifproc(){
        mustbe(TK.IF);
        gcprint("if(");
        expression();
        gcprint(")");
        mustbe(TK.THEN);
        block();
        while( is(TK.ELSIF) ) {
            scan();
            gcprint("else if(");
            expression();
            gcprint(")");
            mustbe(TK.THEN);
            block();
        }
        if( is(TK.ELSE) ) {
            scan();
            gcprint("else");
            block();
        }
        mustbe(TK.END);
    }

    private void whileproc(){
        mustbe(TK.WHILE);
        gcprint("while(");
        expression();
        gcprint(")");
        mustbe(TK.DO);
        block();
        mustbe(TK.END);
    }

    private void forproc(){
        mustbe(TK.FOR);
        gcprint("for(");
        String id = tok.string;
        Entry iv = null; // index variable in symtab
        if( is(TK.ID) ) {
            iv = lvalue_id_index(tok.string, tok.lineNumber);
            iv.setIsIV(true); // mark Entry as IV
            scan();
        }
        else {
            parse_error("missing id on left-hand-side of assignment in for");
        }
        mustbe(TK.ASSIGN);
        gcprint("=");
        expression();
        gcprint(";");
        boolean up = true;
        if( is(TK.TO) ) {
            up = true;
        }
        else if( is(TK.DOWNTO) ) {
            up = false;
        }
        else
            parse_error("for statement is missing to/downto");
        scan();
        gcprintid(id);
        gcprint(up?"<=":">=");
        expression();
        mustbe(TK.DO);
        gcprint(";");
        gcprintid(id);
        gcprint(up?"++)":"--)");
        block();
        mustbe(TK.END);
        iv.setIsIV(false); // mark Entry as no longer IV
    }

    private void repeat(){
	mustbe(TK.REPEAT);
	gcprint("do");
	block();
	mustbe(TK.UNTIL);
	gcprint("while(!(");
	expression();
	gcprint("));");
    }

    private void expression(){
        simple();
        while( is(TK.EQ) || is(TK.LT) || is(TK.GT) ||
               is(TK.NE) || is(TK.LE) || is(TK.GE)) {
            if( is(TK.EQ) ) gcprint("==");
            else if( is(TK.NE) ) gcprint("!=");
            else gcprint(tok.string);
            scan();
            simple();
        }
    }

    private void simple(){
        term();
        while( is(TK.PLUS) || is(TK.MINUS) ) {
            gcprint(tok.string);
            scan();
            term();
        }
    }

    private void term(){
        factor();
        while(  is(TK.TIMES) || is(TK.DIVIDE) ) {
            gcprint(tok.string);
            scan();
            factor();
        }
    }

    private void factor(){
        if( is(TK.LPAREN) ) {
            gcprint("(");
            scan();
            expression();
            mustbe(TK.RPAREN);
            gcprint(")");
        }
        else if( is(TK.ID) ) {
        	Token temp = tok;
        	scan();
        	if ( is(TK.LBRACKET) ) {
        		scan(); // go past openbr
        		Entry e = rvalue_array(temp.string, temp.lineNumber);
        		gcprint("x_"+temp.string+"[(-1)*"+e.getArrayOffset()+"+");
        		//expression();
			bc(temp, e.getArrayOffset(), e.getArraySize());
        		mustbe(TK.RBRACKET);
        		gcprint("]");
        	}
        	else
        		rvalue_id(temp.string, temp.lineNumber);
        }
        else if( is(TK.NUM) ) {
            gcprint(tok.string);
            scan();
        }
        else
            parse_error("factor");
    }

    private Entry lvalue_id(String id, int lno) {
        Entry e = symtab.search(id);
        if( e == null) {
            System.err.println("undeclared variable "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        if( !e.isVar()) {
        	if (e.isArray()) { // arrays get special message
        		System.err.println("missing subscript for array "+ id + " on line "
                        + lno);
            	System.exit(1);
        	}
            System.err.println("constant on left-hand-side of assignment "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        if( e.getIsIV()) {
            System.err.println("index variable on left-hand-side of assignment "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        gcprintid(id);
        return e;
    }
    
    // special lvalue_id for index variables
    private Entry lvalue_id_index(String id, int lno) {
    	Entry e = symtab.search(id);
    	if (e != null && e.isArray()) {
    		System.err.println("array on left-hand-side of assignment (used as index variable) "
					+ id + " on line " + lno);
			System.exit(1);
    	}
    	return lvalue_id(id, lno);
    }
    
    private Entry lvalue_array(String id, int lno) {
    	Entry e = symtab.search(id);
        if( e == null) {
            System.err.println("undeclared variable "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        if( !e.isArray()) {
            System.err.println("subscripting non-array "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        // does not generate code
        return e;
    }

    private void rvalue_id(String id, int lno) {
        Entry e = symtab.search(id);
        if( e == null) {
            System.err.println("undeclared variable "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        if (e.isArray()) { // array with no []
        	System.err.println("missing subscript for array "+ id + " on line "
                    + lno);
        	System.exit(1);
        }
        gcprintid(id);
    }
    
    private Entry rvalue_array(String id, int lno) {
    	Entry e = symtab.search(id);
        if( e == null) {
            System.err.println("undeclared variable "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        if( !e.isArray() ) {
            System.err.println("subscripting non-array "+ id + " on line "
                               + lno);
            System.exit(1);
        }
        return e;
    }


    // is current token what we want?
    private boolean is(TK tk) {
        return tk == tok.kind;
    }

    // ensure current token is tk and skip over it.
    private void mustbe(TK tk) {
        if( ! is(tk) ) {
            System.err.println( "mustbe: want " + tk + ", got " +
                                    tok);
            parse_error( "missing token (mustbe)" );
        }
        scan();
    }
    // same as mustbe but does not scan
    private void mustbeNoScan(TK tk) {
    	if( ! is(tk) ) {
            System.err.println( "mustbe: want " + tk + ", got " +
                                    tok);
            parse_error( "missing token (mustbe)" );
        }
    }
    
    boolean first(TK [] set) {
        int k = 0;
        while(set[k] != TK.none && set[k] != tok.kind) {
            k++;
        }
        return set[k] != TK.none;
    }

    private void parse_error(String msg) {
        System.err.println( "can't parse: line "
                            + tok.lineNumber + " " + msg );
        System.exit(1);
    }
}
