BEGIN
DEFINE CLASS Stack
    DECLARE arr AS ARRAY
    DECLARE top, capacity AS INTEGER

    FUNCTION Stack(stackSize)
        SET capacity = stackSize
        SET top = -1
        RESIZE arr TO stackSize
    END FUNCTION

    FUNCTION push(value)
        IF top == capacity - 1 THEN
            PRINT "Stack Overflow"
            RETURN
        END IF
        INCREMENT top
        SET arr[top] = value
    END FUNCTION

    FUNCTION pop()
        IF top == -1 THEN
            PRINT "Stack Underflow"
            RETURN
        END IF
        SET temp = arr[top]
        DECREMENT top
        RETURN temp
    END FUNCTION

    FUNCTION peek()
        IF top == -1 THEN
            PRINT "Stack is Empty"
            RETURN
        END IF
        RETURN arr[top]
    END FUNCTION

    FUNCTION isEmpty()
        RETURN top == -1
    END FUNCTION
END CLASS
Do phuc tap: O(n)
