package txtExtEvent;

import static kbuilder.common.Common.*;
import javax.swing.JTextField;
import javax.swing.event.CaretEvent;

import java.util.ArrayList;
import java.util.List;

/*
 * Я добавил класс нового компонента/
Это расширенное техтовое поле
 */
public class myTxt extends JTextField 
{
    public myTxt()
    {
        super();
    }
    
    // Добавить массив интерфейсов подписчиков
    List<NewTxtListener> subscribers = new ArrayList<>( 0 );

    // Медод добавления интерфейса подписчика
    public synchronized void addListener( NewTxtListener listener )
    {
        if( !subscribers.contains( listener ) )
        {
            subscribers.add( listener );
        }
    }

    // Медод удаления подписки
    public synchronized void removeListener( NewTxtListener listener )
    {
        subscribers.remove( listener );
    }


     @Override
     protected void fireCaretUpdate(CaretEvent e) 
     {
         super.fireCaretUpdate(e);
         // пока просто выводим в консоль техт
         //p(getText());
         
         String text = getText();
         p( text );
         
         for( NewTxtListener listener: subscribers )
         {
             listener.onNewTxtEvent( new NewTxtEvent( text ) );
         }
         // необходимо добавить вызов метода добавленного интерфейса
         // и реализовать алгоритм выделения слова
     }

}
