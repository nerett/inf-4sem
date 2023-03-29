package javajni;

/**
 *
 * @author mipt
 */
public class JavaJNI
{
    private native void nativePrint();

    static
    {
        System.load( "/home/shob/Dev/Krasilnikov/4sem/4-JNI/libJNIdll.so" );
    }      
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        JavaJNI j = new JavaJNI();
        j.nativePrint();
    }
}
