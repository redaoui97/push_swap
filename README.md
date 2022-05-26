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
  <li>sa(swap a):Swap the first 2 elements at the top of stacka. Do nothing if there is only one or no elements.</li>
  <li>sb(swap b):Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.</li>
  <li>ss:sa and sb at the same time.</li>
  <li>pa(push a):Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.</li>
  <li>pb(push b):Take the first element at the top of a and put it at the top of b. Do nothing if a isempty.</li>
  <li>ra(rotate a):Shift up all elements of stack a by 1. The first element becomes the last one.</li>
  <li>rb(rotate b):Shift up all elements of stack b by 1. The first element becomes the last one.</li>
  <li>rr:ra and rb at the same time.</li>
  <li>rra(reverse rotate a):Shift down all elements of stack a by 1. The last element becomes the first one.</li>
  <li>rrb(reverse rotate b):Shift down all elements of stack b by 1. The last element becomes the first one.</li>
  <li>rrr:rra and rrb at the same time.</li>
  </ul>
  	<h3>Third step: Implement sorting algorithm</h3>
  		<h4>I - picking the fastest sorting algorithm</h4>
		Cases: 
		<ul>
			<li>3 random numbers: There are 6 possible cases for 3 random numbers, but 3 of them can get handled by is_sorted functions (a function that checks if the list is sorted) so we can use a naive sorting algorithm to sort the list in less than 3 steps</li>
			<li>5 random numbers: We'll use the same algorithm that we've used with the 3 random numbers algo. First we push the 2 smallest numbers in stack_a into stack_b then we sort the 3 elements in stack_a using the 3 elements algorithms, before pushing back the 2 elements from stack_b back again to stack_a</li>
      <li>Now for the most important algorithm of the this project:<br>
      This algorhtm works with 6+ numbers (it sometimes doesn't give 5/5 points on correction for the 500 numbers list).<br>
      The idea is simple : 
      <ol>
        <li>Calculate the longest increasing subsequence in the stack (find the longest subsequence in a list of numbers)</li>
        <li>Sends the numbers that doesn't belong to the longest increasing subsequence to stack_b</li>
        <li>Push the values back from stack_b into stack_a according to the number of moves requered to be in the right position in stack_a</li>
        <li>And finally sending the minimum number to the head of stack_a</li>
      </ol>
      </li>
  </p>


