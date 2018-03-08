g++ -I /usr/local/opt/boost/include -L /usr/local/opt/boost/lib -std=c++11 simple_boost.cpp -lboost_system -lboost_filesystem -lboost_iostreams


LINUX OUTPUT


```
Processed line a.out
Processed line README.md
Processed line simple_boost.cpp
Processed line a.out
Processed line README.md
Processed line simple_boost.cpp
```


MAC OUTPUT


```
Processed line README.md
Processed line a.out
Processed line simple_boost.cpp
```


This shows there is something wrong happening even with a simple example.


What doesn't help.

* closing the file descriptor doesn't sovle this problem
* adding a sleep doesn't help (30 seconds)
* closing + sleep doesn't work
