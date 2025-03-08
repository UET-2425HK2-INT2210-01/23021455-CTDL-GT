BEGIN
DEFINE CLASS Node
    DECLARE data AS INTEGER
    DECLARE next AS POINTER TO Node
END CLASS

DEFINE CLASS Queue
    DECLARE front AS POINTER TO Node
    DECLARE rear AS POINTER TO Node

    FUNCTION Queue()
        SET front = NULL
        SET rear = NULL
    END FUNCTION

    FUNCTION enqueue(value)
        CREATE newNode WITH data = value AND next = NULL
        IF rear IS NULL THEN
            SET front = newNode
            SET rear = newNode
        ELSE
            SET rear.next = newNode
            SET rear = newNode
        END IF
    END FUNCTION

    FUNCTION dequeue()
        IF front IS NULL THEN
            PRINT "Queue is empty"
            RETURN
        END IF
        SET temp = front
        SET front = front.next
        IF front IS NULL THEN
            SET rear = NULL
        END IF
        DELETE temp
    END FUNCTION

    FUNCTION peek()
        IF front IS NULL THEN
            PRINT "Queue is empty"
            RETURN
        END IF
        RETURN front.data
    END FUNCTION

    FUNCTION isEmpty()
        RETURN front IS NULL
    END FUNCTION
END CLASS
Do phuc tap:O(n)
