## Сортировка бинарными вставками

#### Из графиков видно, что:

1. Cортировка массива, элементы которого расположены по убыванию, является худшим случаем для данного алгоритма. В этом случае его 
сложность выраждается в O(n^2). Происходит это так как на каждой итерации приходится делать максимальное число бинарных поисков (так как текущее число всегда оказывается меньше того, с которым оно сравнивается)

2. Сортировка почти отсортированного массива является лучшим случаем для данного алгоритма (из приведённых .png файлов может показаться, что полученные измерения и вовсе равны нулю, однако это не так). В этом случае его сложность равна O(n*log(n)), практически O(n). Происходит это из-за того, что большинство элементов уже находится на своих местах, а для неотсортированных элементов потребуется всего несколько итераций бинарного поиска для нахождения правильной позиции.

3. Сортировки массивов из случайных чисел 0-5 и 0-4000 по сложности и времени исполнения находятся ровно между двумя вышеупомянутыми. Также сортировка чисел 0-4000 оказалась несколько сложней, чем 0-5 (так как во втором случае большинство элементов имеют очень близкие значения (собственно, каждый элемент равен 20% других элементов массива), соотвественно для нахождения верной позиции элементов 0-5 потребуется значительно меньше итераций бинарного поиска, чем для 0-4000).

> Графики измерений времени и количества операций выглядят практически одинаково.

> Выбросы наблюдаются только на графике измерений времени для массива из 4100 элементов, так что мне кажется, что они связаны непосредственно с работой процессора.