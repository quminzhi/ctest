#include "cirqueue.h"

CirQueue::CirQueue(int capacity)
    : array_(new int[capacity]), front_(-1), rear_(-1), size_(0),
      capacity_(capacity) {}

CirQueue::CirQueue(const CirQueue &o)
    : array_(new int[o.capacity_]), front_(o.front_), rear_(o.rear_),
      size_(o.size_), capacity_(o.capacity_) {
  for (int i = 0; i < capacity_; ++i) {
    array_[i] = o.array_[i];
  }
}

// Implementation of the copy assignment operator
CirQueue &CirQueue::operator=(const CirQueue &o) {
  if (this != &o) {
    // Deallocate existing array
    delete[] array_;

    // Copy data from the o object
    capacity_ = o.capacity_;
    size_ = o.size_;
    front_ = o.front_;
    rear_ = o.rear_;

    // Allocate a new array and copy elements
    array_ = new int[capacity_];
    for (int i = 0; i < capacity_; ++i) {
      array_[i] = o.array_[i];
    }
  }
  return *this;
}

CirQueue::~CirQueue() { delete[] array_; }

bool CirQueue::is_empty() const { return size_ == 0; }

bool CirQueue::is_full() const { return size_ == capacity_; }

void CirQueue::enqueue(const int &e) {
  if (is_full()) {
    std::cerr << "queue is full. cannot enqueue." << std::endl;
    exit(1);
  }

  if (is_empty()) {
    front_ = rear_ = 0;
  } else {
    rear_ = (rear_ + 1) % capacity_;
  }

  array_[rear_] = e;
  size_++;
}

int CirQueue::dequeue() {
  if (is_empty()) {
    std::cerr << "queue is empty. cannot dequeue." << std::endl;
    exit(-1);
  }

  int popped = array_[front_];

  if (front_ == rear_) {
    front_ = rear_ = -1;
  } else {
    front_ = (front_ + 1) % capacity_;
  }

  size_--;

  return popped;
}

int CirQueue::peek() const {
  if (is_empty()) {
    std::cerr << "queue is empty. no front element" << std::endl;
    exit(1);
  }

  return array_[front_];
}

void CirQueue::show_queue() const {
  std::cout << "Queue: ";

  if (is_empty()) {
    std::cout << "empty\n";
    return;
  }

  int i = front_;
  do {
    std::cout << array_[i] << " ";
    i = (i + 1) % capacity_;
  } while (i != (rear_ + 1) % capacity_);

  std::cout << std::endl;
}