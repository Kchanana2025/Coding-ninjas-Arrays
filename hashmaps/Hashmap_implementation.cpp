// agar hm key ko template rakh lenge toh hm hash code kaise define krege because hashcode toh data type pr depend krta hai
// abhi ke lie hm keys ko of type string choose kr rhe hai aur value ko toh template use kr hi skte hai
// agar hamien generalize krna hai toh hamien hr type ke lie ek common hash code sochna padhega
// badme hm aise generalize bhi kr skte hain ki in inbuilt classes ke lie jin  jin mein ye function hai unme ye hashcode use krlo
template <typename V>
class MapNode // node of link list
{

public:
    string key;
    V value;
    MapNode *next;
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode() // recursive destructor
    {
        delete next;
    }
};
template <typename V>
class ourmap
{
    MapNode<V> **buckets; // it is our array we declared it as double pointer as it is array of pointers i.e head of all link lists
    int size;             // stores total size
    int numBuckets;       // stores no of buckets

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        // it is not right to let garbage stay in our arrays
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i]; // firstly we deleted all link lists recursively through constructor
        }
        delete[] buckets; // then deleted array also (in which head of all link lists have been saved)
    }
    int size()
    {
        return count;
    }
    V getvalue(string key) // return value corresponding to a particular key
    {
    }

private:
    int getbucketindex(string key)
    {
        // calculation of hashcode
        int hashcode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37; // koi bhi prime no set krna hota hai
            currentCoeff = currentCoeff % numBuckets;
        }
        // compression
        return hashcode % numBuckets;
    }

public:
    void insert(string key, V value) // inserts key value pair
    {
        int bucketindex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            // key is already present in link list just update the value
            if (head->key == key)
            {
                head->value = value;
                return;
            }
        }
        // if cantrol reaches here that means key is not  present in link list we need to create a new key value pair

        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head; // we are inserting node in front of link list
        bucket[bucketIndex] = node;
        count++;
    }
    V remove(string key) // delete key value pair(of the  key accepted as a parameter ) and return its value
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL) // we are finding key in link list jab tak head NULL ke barabar na ho jaye
        {
            if (head->key == key)
            {
                if (prev == NULL) // this means that first element of link list contained the key in that case prev is NULL,ye wala case alag se isliye banana padha because NULL-> se segmentation fault ajata agar ye prev->next=head->next krte ,secondly bucketindex pr head bhi toh update karoge
                {
                    buckets[bucketIndex] = head->next; // bucketindex will now contain new head
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL; // agar aise hi delete head likh denge toh recursive destructor call hoga aur head ke aage ki poori link list delete ho jayegi isliye hmne head->next=NULL kr dia
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // agar cantrol yaha pr aaya hai toh mtlb key present hi nai hogi toh return 0 krdo
                  // 0 kisi node ki value actually bhi ho skti thi pr filhal hmare pass option nai tha toh hmne 0 return kr dia
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
        }
        return 0;
    }
};
// array will contain  of heads of all link lists so its data type will be of double pointer
