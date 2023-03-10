## Сортировка пузырьком

#### Из графиков видно, что:

1. Для всех видов измерений сложность равна O(n^2), так как это самый простой вид сортировки, в любом случае выполняющий n^2 итераций цикла.

2. Графики измерений времени и числа операций достаточно заметно различаются. Видно, что скорость роста первого от числа элементов в массиве выше скорости роста для второго. Происходит это, как мне кажется, из-за того, что перестановка двух элементов занимает относительно много времени, хоть и включает в себя не очень большое число элементарных операций. Соответственно, так как число перестановок значительно возростает при увеличении размера сортируемого массива, то и скорость роста времени оказывается быстрее скорости роста числа операций.

> Выбросы на графиках по сути не наблюдаются.