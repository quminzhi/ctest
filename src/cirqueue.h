#pragma once

#include <iostream>

class CirQueue {
public:
  CirQueue(int capacity);
  CirQueue(const CirQueue &other);            // Copy constructor
  CirQueue &operator=(const CirQueue &other); // Copy assignment operator
  ~CirQueue();

  bool is_empty() const;
  bool is_full() const;

  void enqueue(const int &element);
  int dequeue();
  int peek() const;

  void show_queue() const;

private:
  int *array_;
  int front_, rear_;
  int size_, capacity_;
};