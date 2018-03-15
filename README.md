# C_programming


It's gonna take time to practice all the algorithms


1.Bubble_sort Time complexity O(n^2)
2.Insertion_Sort Time complexity O(n^2)
3.Merge_sort Time complexity O(nlogn)
4.Quick_sort Time complexity O(nlogn)
5.Selection_sort Time complexity O(n^2)






Dijkstra double stack evaluation method based on 'Algorithms Fourth Edtion':

Strength : 
Capable of solving simple problem, when there is only one operation in one parenthese, which means two arguments in one parenthese (ep. (1+2)).

Acceptable input : (1 + ((2 + 3) * (4 * 5)))

defect : 

It cannot solve (1 + 2 * 3) + 3, and I haven't added precedence rules of arithmetic, for example, mulitplication and division should be calculated first.