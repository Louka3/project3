console.log("hello");

const inputArr = ["ab", "ab", "bc", "cd", "ef", "gh", "ab", "x"];

// class Node {
//   constructor(input){
//     this.next = null;
//     this.data = {
//       word: input,
//       count: 1
//     };
//     this.prev = null;
//   }
// }

// class LinkedList {
//   constructor(){
//     // start the list
//     this.head = null;
//     this.tail = null;
//   }
//   append(input){
//     // append the node to the end of the list
//     const node = new Node(input);
//     if(this.head === null){
//       this.head = node;
//       this.tail = node; 
//     }
//     else {
//       // put the node at the end of the list
//       node.prev = this.tail;
//       this.tail.next = node;
//       this.tail = node;
//     }
//   }
//   search(input){
//     // traverse the list to see if the word is already accounted for
//     if(this.head === null){
//       this.append(input);
//       return;
//     }
//     let current = this.head;
//     while(current){
//       if(current.data.word === input){
//         current.data.count += 1;
//         // I want the nodes with the highest count to be at the front of the list, since the list should be
//         // in decreasing order. 
//         // check the current count vs the count of the previous node
//         // if(current.prev === null) return;
//         while(current.prev !== null && current.data.count > current.prev.data.count){
//           //* this need to be looped. but whats the condition?
//           const tempNext = current.next; // ref to next node
          
//           // const newPrev = current?.prev?.prev; // new prev for current node after swap
//           const newPrev = current.prev.prev === null ? null : current.prev.prev
//           const swapping = current.prev; // the node to be swapped
//           current.next = swapping; // changing next so the previous node is now further ahead in the list 
//           current.prev = newPrev; // establishing link to the rest of the list ahead of current
//           if(current.prev === null) this.head = current; // changing head of list if necesarry
//           swapping.next = tempNext; // establishing link to the rest of the list past swapped node
//           swapping.prev = current; // finally, linking the swapped node back to current
//         }
        
//         break; //! ? i know i need to break out of this loop but i need to do something else before that
//       }
//       else {
//         if(current.next){
//           current = current.next;
//           continue;
//         }
//         else{
//           this.append(input);
//           current = null;
//         }
//       }
//     }
//   }
//   print(){
//     let current = this.head;
//     while(current !== null){
//       console.log("Word: ", current.data.word);
//       console.log("Count: ", current.data.count);
//       console.log("-----")
//       current = current.next;
//     }
//     console.log("End of list");
//   }

// }


class Node {
  constructor(input){
    this.next = null;
    this.data = {
      word: input,
      count: 1
    };
    this.prev = null;
  }
}

class LinkedList {
  constructor(){
    this.head = null;
    this.tail = null;
  }

  add(input){
    const node = new Node(input);
    if(this.head === null){
      this.head = node;
      this.tail = node;
    }
    else{
      let current = this.head;
      while(current !== null){
        current.next
      }
    }
  }

  traverse(input){
    let current = this.head;
    while(current !== null){
      if(current.data.word === input){
        current.data.count += 1;
        // check if the node's data.count is greater than the next node
        
      }
      else{
        current = current.next;
        continue;
      }
    }
    this.add(input);
  }

  print(){

  }




}


const ll = new LinkedList();
// ll.search('word1');
// ll.search('word2');
// ll.search('word3');
// ll.search('word1');
inputArr.forEach(ele => {
  ll.search(ele);
})

ll.print();

/*

make linked list
add input
  first input, set as head and tail
add next input
  check if current input matches input at current node
    if yes, increment count by 1, stop the loop, exit
    if no, check the next nodes input
    repeat until the end of the list is traversed, then call the add method
  now we need to find out where the inputs that have a frequency of 1 end (maybe we keep track of this as a pseudo-tail?)
  



*/
