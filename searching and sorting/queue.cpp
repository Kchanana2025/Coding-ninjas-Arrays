class queue_using_array
{
    int *data;
    int startindex;
    int nextindex;
    int size;
    int capacity;

public:
    queue_using_array(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        startindex = -1;
        nextindex = 0;
        data = new int[capacity];
    }
}