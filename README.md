<h1>Push swap</h1>
4th project on the 42 cursus

<h3>Objectives</h3>
<p>
The objectif of this project is always a very important stop in a developer's journey. It is often the first encounter with the concept of complexity.
Sorring algorithms and their complexity are part of the classic questions discussed during job interviews. It's probably a goodtime to look at these concepts since you'll have to face them at some point.
The learning objectives of this project are rigor, use of C, and usee of basic algorithms, especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from on integers configuration to another the most efficient sorting solution can differ.
</p>
-----------------------------------------
  <h3>Stack</h3>
  <p>
    A stack is a linear data structure which follows a particular order in which the operations are performed (Lifo-last in firt out/Filo-first in last out)
 
  <h3>First step: implement a stack using linked lists</h3>
  Linked list: sequence of data structures which are connected via links:
  <ul>
  <li>Simple linked list: forward only</li>
  <li>Doubly linkeed list: Forward and backward (which we will use now)</li>
  <li>Circular linked list: forward, backwards and last item contains link of the first element as next, first has link to the last element as previous </li>
  </ul>
  <h4>Linked list conception:</h4>
  Struct : node
  <ul>
    <li>Position: position of the node in the list</li>
    <li>Value: value of the node (integer)</li>
    <li>Previous: address of the previous node (NULL if first)</li>
    <li>Next: address of the next node (NULL if last)</li>
    <li>First: address of the first node</li>
    <li>Last: address of the last node</li>
  </ul>
  Operations on list:
  <ul>
    <li>new_node: creates a new node</li>
    <li>add_element: adds node to the list</li>
    <li>list_size: returns the size of the list</li>
    <li>is_empty: returns 1 if list is empty(not sure if needed so far)</li>
    <li>clear_list: frees all nodes from the list</li>
    <li>Show_elements: display all the nodes on the list</li> 
  </ul>
  <h3>Second step: Implement the movees</h3>
  <ul>
  <li>(done)sa(swap a):Swap the first 2 elements at the top of stacka. Do nothing if there is only one or no elements.</li>
  <li>(done)sb(swap b):Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.</li>
  <li>(done)ss:sa and sb at the same time.</li>
  <li>(done)pa(push a):Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.</li>
  <li>(done)pb(push b):Take the first element at the top of a and put it at the top of b. Do nothing if a isempty.</li>
  <li>(done)ra(rotate a):Shift up all elements of stack a by 1. The first element becomes the last one.</li>
  <li>(done)rb(rotate b):Shift up all elements of stack b by 1. The first element becomes the last one.</li>
  <li>(done)rr:ra and rb at the same time.</li>
  <li>(done)rra(reverse rotate a):Shift down all elements of stack a by 1. The last element becomes the first one.</li>
  <li>(done)rrb(reverse rotate b):Shift down all elements of stack b by 1. The last element becomes the first one.</li>
  <li>(done)rrr:rra and rrb at the same time.</li>
  </ul>
  	<h3>Third step: Implement sorting algorithm</h3>
  		<h4>I - picking the fastest sorting algorithm</h4>
		*work inspired from <a href=https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a>here</a>
		Cases: 
		<ul>
			<li>3 random numbers: There are 5 possible cases for 3 random numbers so we can use a naive sorting algorithm to sort the list in few steps, by manually sorting them. (I need to add an image here)</li>
	<li>5 random numbers: </li> 
	------------------<br>
	1-Find the LIS (longest incresing subsequence)
  </p>
    
