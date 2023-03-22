package txtExtEvent;

/**
 * Любой компонент? желающий обрабатывать наше событие должен реализовать 
 * этот интерфейс
 * В данном примере это наша форма
 * @author mipt
 */
public interface NewTxtListener 
{
    // Добавить метод, который мы будем вызывать у подписчика/  
    public void onNewTxtEvent( NewTxtEvent event );
}
