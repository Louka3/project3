console.log("hello");

const input = ["ab", "ab", "bc", "cd", "ef", "gh", "ab", "x"];

const Node = (input) => {
  this.next = null;
  this.data = {
    word: input,
    count: 1
  }
}

class LinkedList {
  constructor(){
    // start the list
    this.head = null;
    this.tail = null;
  }
  append(word){
    // append the node to the end of the list
    const node = new Node(word);
    if(this.head === null){
      this.head = node;
    }
    else {
      this.tail.next = node;
      this.tail = node;
    }
  }

}



