#include "cirqueue.h"
#include <gtest/gtest.h>

// Test fixture for CirQueue
class CirQueueTest : public ::testing::Test {
protected:
  // Declare any members that you want to reuse across tests
  CirQueueTest() {
    // Initialization code (if needed) before each test
  }

  // Clean up code (if needed) after each test
  virtual ~CirQueueTest() {}

  // You can declare member variables here that you want to be available to all
  // your tests
};

// Test case for the constructor and is_empty function
TEST_F(CirQueueTest, ConstructorAndIsEmpty) {
  CirQueue queue(5);             // Create a CirQueue object with capacity 5
  EXPECT_TRUE(queue.is_empty()); // The queue should be empty after creation
}

// Test case for enqueue and is_full functions
TEST_F(CirQueueTest, EnqueueAndIsFull) {
  CirQueue queue(3); // Create a CirQueue object with capacity 3
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  EXPECT_TRUE(queue.is_full()); // The queue should be full after three enqueues
}

// Test case for dequeue and peek functions
TEST_F(CirQueueTest, DequeueAndPeek) {
  CirQueue queue(3); // Create a CirQueue object with capacity 3
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  EXPECT_EQ(queue.peek(), 1);    // The front element should be 1
  EXPECT_EQ(queue.dequeue(), 1); // Dequeue the front element
  EXPECT_EQ(queue.peek(), 2);    // The front element should now be 2
}

// Test case for show_queue function
TEST_F(CirQueueTest, ShowQueue) {
  CirQueue queue(3); // Create a CirQueue object with capacity 3
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  // Redirect cout to a stringstream to capture the output
  testing::internal::CaptureStdout();
  queue.show_queue();
  std::string output = testing::internal::GetCapturedStdout();

  // Check if the output matches the expected format
  EXPECT_EQ(output, "Queue: 1 2 3 \n");
}