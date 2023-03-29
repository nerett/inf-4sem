package javajni;

import static java.lang.System.out;

/**
 *
 * @author mipt
 */
public class JavaJNI
{
    private native String nativePrint( int i );
    private native void nativeChange( int i );
    public static String s;

    static
    {
        System.load( "/home/shob/Dev/Krasilnikov/4sem/4-JNI/libJNIdll_2.so" );
    }      
    /**
     * @param args the command line arguments
     */
    public static void main( String[] args )
    {
        JavaJNI j = new JavaJNI();
        out.println( "1" );
        s = j.nativePrint( 3 );
        out.println( s );
        j.nativeChange( 3 );
        out.println( s );
        try
        {
          Thread.sleep( 3000 );
        } catch ( InterruptedException ex )
        {
        }
        out.println( "END" );
    }
}
