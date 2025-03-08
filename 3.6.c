BEGIN
DEFINE CLASS Node
    DECLARE data AS INTEGER
    DECLARE next AS POINTER TO Node
END CLASS

DEFINE CLASS Stack
    DECLARE top AS POINTER TO Node

    FUNCTION Stack()
        SET top = NULL
    END FUNCTION

    FUNCTION push(value)
        CREATE newNode
        SET newNode.data = value
        SET newNode.next = top
        SET top = newNode
    END FUNCTION

    FUNCTION pop()
        IF top == NULL THEN
            PRINT "Stack Underflow"
            RETURN
        END IF
        SET temp = top
        SET top = top.next
        RETURN temp.data
        DELETE temp
    END FUNCTION

    FUNCTION peek()
        IF top == NULL THEN
            PRINT "Stack is Empty"
            RETURN
        END IF
        RETURN top.data
    END FUNCTION

    FUNCTION isEmpty()
        RETURN top == NULL
    END FUNCTION
END CLASS
 Do phuc tap: O(n)
