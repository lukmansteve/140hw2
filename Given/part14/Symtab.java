import java.util.*;

// Symtab is a Stack of ArrayLists of "Entries"

public class Symtab {

    private Stack<ArrayList<Entry>> st;
    // level of current symtab block
    private int level;

    public Symtab(){
        st = new Stack<ArrayList<Entry>>();
        level = -1;
    };

    // start of symtab block
    public void begin_st_block() { // push block
        ArrayList<Entry> newBlock = new ArrayList<Entry>();
        st.push(newBlock);
        level++;
    }

    // end of symtab block
    public void end_st_block() { // pop block
        st.pop();
        level--;
    }

    public int get_level() {
        return level;
    }

    // add var or const entry to current block
    public boolean add_entry(String myid, int myline, TK myVarOrConstOrArray) {
        Entry e = search_this_block(myid);
        if (e != null) {//if e is there
            System.err.println(e.whatAreYou() +
                                   " " + myid +
                                   " is redeclared on line "+
                                   myline);
                return false;
        }
			//otherwise it's not so:
        Entry p = new Entry(myid, myline, myVarOrConstOrArray);
        st.peek().add(p);//add the entry to the top array list in the stack.
        return true;
    }
    
    // add array to current block
    // methods are identical except: here array offset and size is also stored
    public boolean add_entry(String myid, int myline, TK myVarOrConstOrArray, int offset, int size) {
        Entry e = search_this_block(myid);
        if (e != null) {//if e is there
            System.err.println(e.whatAreYou() +
                                   " " + myid +
                                   " is redeclared on line "+
                                   myline);
                return false;
        }
			//otherwise it's not so:
        Entry p = new Entry(myid, myline, myVarOrConstOrArray, offset, size);
        st.peek().add(p);//add the entry to the top array list in the stack.
        return true;
    }

    // these search routines search
    //    the *stack*  of blocks backwards.
    //    individual blocks forward (either order would work).

    // also, can't (easily) use .contains to search
    // within block of symbol table because entries contain more
    // than just a name and want to search based only on name.

    public Entry search(String myid) {
        // for scoping, search list backwards.
        // check for identifer in this block first, outward to global block.
        ListIterator<ArrayList<Entry>> blocks = st.listIterator(st.size());
        // now can go backwards.
        while( blocks.hasPrevious() ) {
            ArrayList<Entry> block = blocks.previous();
            for( Entry p : block) {
                if( p.getName().equals(myid) ){
                    return p;
                }
            }
        }
        return null;
    }

    private Entry search_this_block(String myid) {
        ArrayList<Entry> block = st.peek();//top block
        for(/*all*/ Entry p : block) {
            if( p.getName().equals(myid) ) {
                return p;
            }
        }
        return null;
    }

    // some of these search methods could be combined ...
    public Entry search_level(int slevel, String myid) {
        if (slevel > level) {
            return null;
        }
        if (slevel < 0) { // be defensive
            System.err.println("oops slevel<0 " + slevel);
            System.exit(1);
        }
        // go directly to right block:
        ArrayList<Entry> block = st.elementAt(level-slevel);
        // now search that block:
        for( Entry p : block) {
            if( p.getName().equals(myid) ){
                return p;
            }
        }
        return null;
    }

}
