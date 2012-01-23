import java.util.*;

class Entry {
    private String name;        // name of symbol.
    private int lineNumber;     // line on which declared
    private TK varOrConstOrArray;      // variable or const?
    private boolean isIV ;      // is presently index variable?
    // arrays:
    private int array_offset;   // offset for bounds
    private int array_size;     // size of array

    public Entry(String name, int lineNumber, TK varOrConstOrArray) {
        this.name = name;
        this.lineNumber = lineNumber;
        this.varOrConstOrArray = varOrConstOrArray;
        this.isIV = false;
    }
    public Entry(String name, int lineNumber, TK varOrConstOrArray, int array_offset, int array_size) {
        this.name = name;
        this.lineNumber = lineNumber;
        this.varOrConstOrArray = varOrConstOrArray;
        this.isIV = false;
        this.array_offset = array_offset;
        this.array_size = array_size;
    }
    String getName() {
        return name;
    }
    int getLineNumber() {
        return lineNumber;
    }
    boolean isVar() {
        return (varOrConstOrArray == TK.VAR);
    }
    boolean isConst() {
        return (varOrConstOrArray == TK.CONST);
    }
    boolean isArray() {
    	return (varOrConstOrArray == TK.ARRAY);
    }
    int getArrayOffset() {
    	return array_offset;
    }
    int getArraySize() {
    	return array_size;
    }
    boolean getIsIV() {
        return isIV;
    }
    void setIsIV(boolean is) {
        isIV = is;
    }
    public String whatAreYou() {
        return  isVar()?"variable"
               :isConst()?"constant"
               :isArray()?"array"
               :"OOPS Entry whatAreYou()";
    }
    public String toString() {
        return name + "  declared on line " + lineNumber + " as "+ varOrConstOrArray;
    }
}
