## Сортировка пузырьком с 1м условием Айверсона

#### Из графиков видно, что:

1. В общем полученные измерения не отличаются от таковых для сортировки пузырьком, т.е. сложность равна O(n^2) для массивов из случайных элементов и массивов отсортированных в обратном порядке.

2. Однако, измерения для почти отсортированного массива крайне низки. Причина этому в том, что для такой сортировки приходится всего 1-2 раза пройтись по массиву, так как большая часть элементов стоит на своих местах, а иные очень к ним близки.

> Причина разницы между графиками измерений времени и числа операций такая же, что и для обычной сортировки пузырьком.

> На графике измерений времени массивов размера 300 наблюдается заметный выброс у отсортированного в обратном порядке массива, объяснить его иначе как работой процессора я не могу (так как на других графиках ничего подобного нет).