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
  search(input){
    // traverse the list to see if the word is already accounted for
    if(this.head === null){
      const node = new Node(input);
      this.head = node;
      return;
    }
    while(current){
      if(current.data.word === input){
        current.data.count += 1;
        // call comparison function
        // i need a way to change the order of the list after running my comparison
        break; //! ? i know i need to break out of this loop but i need to do something else before that
      }
      else {
        if(current.next){
          current = current.next();
          continue;
        }
        else{
          const node = new Node(input);
          current.next = node;
          this.tail = node;
        }
      }
    }
  }
  compare(){

  }

}



