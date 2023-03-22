
package txtExtEvent;

import java.util.EventObject;

/**
 * Новое событие, добавить необходимое поле и конструктор.
 * @author mipt
 */
public class NewTxtEvent extends EventObject
{
    //String text;
    
    public NewTxtEvent( Object source )
    {
        super( source );
        
        //text = new String( ( String )source );
    }    
}
