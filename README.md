# Data-Structures-Project

correction in interpolation search (find_region function) to find b1 and b2, doesn't work properly
when there are duplicates from the left side

e.g:

span(b1, b2) = (1, 21)

Regions within the specified birth count range:
1. Period: 2022, Region: UNKNOWN, Count: 6
2. Period: 2015, Region: UNKNOWN, Count: 12
3. Period: 2013, Region: UNKNOWN, Count: 12
4. Period: 2021, Region: UNKNOWN, Count: 12
5. Period: 2016, Region: UNKNOWN, Count: 15
6. Period: 2017, Region: UNKNOWN, Count: 15
7. Period: 2012, Region: UNKNOWN, Count: 18
8. Period: 2018, Region: UNKNOWN, Count: 18
9. Period: 2020, Region: UNKNOWN, Count: 18
10. Period: 2014, Region: UNKNOWN, Count: 21

BUT, 
Period: 2014, Event: Births, Region: UNKNOWN, Count: 21
Period: 2019, Event: Births, Region: UNKNOWN, Count: 21

there are 2 cases where count = 21

idfk...

+++ TODO: Πρέπει να κρατήσω το άθροισμα των births/deaths για κάθε region απαλείφοντας τον χρόνο.
