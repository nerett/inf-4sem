// 1 Добавить рассчёт общей суммы элементов в evenodd.
// 2 Написать функтур для рассчёта количества букв "А"  в массиве слов.
#include <algorithm>
#include <iostream>
#include <list>

class EvenOddFunctor 
{
    private:
        int even_;
        int odd_;

    public:
        EvenOddFunctor() : even_( 0 ), odd_( 0 ) {}
        
        // какой оператор перегрузили?
        void operator()( int x ) 
        {
            if( x%2 == 0 ) even_ += x;
            else odd_ += x;
        }
        int even_sum() const { return even_; }
        int odd_sum() const { return odd_; }
};

int main() 
{
    EvenOddFunctor evenodd;
    int my_list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // для каждого элемента массива будет выполнено evenodd(текущий элемент)
    evenodd = std::for_each( my_list,
                            my_list + sizeof( my_list ),
                            evenodd );
    std::cout << "Сумма чётных: " << evenodd.even_sum() << "\n";
    std::cout << "Сумма нечётных: " << evenodd.odd_sum() << std::endl;

    // Сумма чётных: 30
    // Сумма нечётных: 25
}
