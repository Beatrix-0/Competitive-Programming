1. Sequence Containers {O(n) or O(1)}
Sequence containers are data structures that maintain the order of elements. They allow you to access elements
sequentially, typically in the order they were inserted. The elements are stored in a linear arrangement, and
the order of insertion is preserved. [ Order based ]

- Vector : 
push_back() , pop_back() , insert() , erase() , clear() , resize() , reserve() , front() , back() , assign() 
swap() , begin() , end() , rbegin() , rend() 
- Deque :
push_back() , push_front() , pop_back() , pop_front() , insert() , erase() , clear() , resize() , front() 
back() , assign() , begin() , end() , rbegin() , rend()


2. Associative Containers { logn }
Associative containers store elements in a way that allows fast retrieval based on keys, rather than the position
of the elements. These containers are typically implemented as balanced binary trees (e.g., red-black trees) 
or hash tables, providing fast search, insertion, and deletion operations. [ Key based]

- Set / multiset :
insert() , erase() , clear() , find() , count() , lower_bound() , upper_bound() , swap() , begin() , end()  
rbegin() , rend() , equal_range() , prev() , next()
- map / multimap :
insert() , erase() , clear() , find() , count() , lower_bound() , upper_bound() , swap() , begin() , end()  
rbegin() , rend() , equal_range() 
- unordered_set :
insert() , erase() , clear() , find() , count() ,  swap() , begin() , end() , equal_range() , bucket_count()
rbegin() , rend() , load_factor() , max_load_factor() , rehash() , reserve()


3. Container Adapters {O(1) or O(logn)}
Container adapters are special kinds of containers that provide a different interface for other existing sequence
containers. They adapt a container by restricting access to certain operations, providing a simpler or more 
specialized interface.

- Stack : [LIFO]
push() , pop() , top() , size() , empty() , swap()
- Queue : [FIFO]
push() , pop()  , size() , empty() , swap() , front() , back()
- Priority_queue :
push() , pop() , top() , size() , empty() , swap()

4. Other type 

- Pair :
make_pair() , swap()
- tuple :
make_tuple() , tie() , swap() , get()
- bitset :
set() , reset() , flip() , all() , any() , none() , count() , size() , test() , to_string() 



