BEGIN
DEFINE CLASS Queue
    DECLARE arr AS ARRAY
    DECLARE size, capacity, front, rear AS INTEGER

    FUNCTION Queue(qSize)
        SET size = 0
        SET front = 0
        SET rear = -1
        SET capacity = qSize
        RESIZE arr TO qSize
    END FUNCTION

    FUNCTION enqueue(x)
        IF size == capacity THEN
            PRINT "Queue is full"
            RETURN
        END IF
        SET rear = (rear + 1) MOD capacity
        SET arr[rear] = x
        INCREMENT size
    END FUNCTION

    FUNCTION dequeue()
        IF size == 0 THEN
            PRINT "Queue is empty"
            RETURN
        END IF
        SET front = (front + 1) MOD capacity
        DECREMENT size
    END FUNCTION

    FUNCTION peek()
        IF size == 0 THEN
            PRINT "Queue is empty"
            RETURN
        END IF
        RETURN arr[front]
    END FUNCTION

    FUNCTION isEmpty()
        RETURN size == 0
    END FUNCTION

    FUNCTION isFull()
        RETURN size == capacity
    END FUNCTION
END CLASS
Do phuc tap: O(n)
