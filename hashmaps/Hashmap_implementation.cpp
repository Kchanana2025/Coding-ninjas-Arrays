// agar hm key ko template rakh lenge toh hm hash code kaise define krege because hashcode toh data type pr depend krta hai
// abhi ke lie hm keys ko of type string choose kr rhe hai aur value ko toh template use kr hi skte hai
// agar hamien generalize krna hai toh hamien hr type ke lie ek common hash code sochna padhega
// badme hm aise generalize bhi kr skte hain ki in inbuilt classes ke lie jin  jin mein ye function hai unme ye hashcode use krlo
#include <string>
#include <iostream>
using namespace std;
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
    int count;            // stores total size
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
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // firstly we deleted all link lists recursively through constructor
        }
        delete[] buckets; // then deleted array also (in which head of all link lists have been saved)
    }
    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        // calculation of hashcode
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37; // koi bhi prime no set krna hota hai
            currentCoeff = currentCoeff % numBuckets;
        }
        // compression
        return hashCode % numBuckets;
    }
    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[numBuckets * 2];
        for (int i = 0; i < (2 * numBuckets); i++)
        {
            buckets[i] = NULL; // garbage addresses must not be present
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        // we are taking ech node and putting it in our hashmap
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        // deleting of original hashmap
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insert(string key, V value) // inserts key value pair
    {
        int bucketIndex = getBucketIndex(key);
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
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count) / numBuckets; // int/int is integer so we multiplied it by 1.0 so that float/int gives float value
        if (loadFactor > 0.7)
        {
            rehash();
        }
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
                if (prev == NULL) // this means that first element of link list contained the key in that case prev is NULL,ye wala case alag se isliye banana padha because NULL-> se segmentation fault ajata agar ye prev->next=head->next krte ,secondly bucketIndex pr head bhi toh update karoge
                {
                    buckets[bucketIndex] = head->next; // bucketIndex will now contain new head
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
    V getValue(string key) // return value corresponding to a particular key
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
    double getloadfactor()
    {
        double loadFactor = (1.0 * count) / numBuckets;
        return loadFactor;
    }
};
// array will contain  of heads of all link lists so its data type will be of double pointer
int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getloadfactor() << endl;
    }
    cout << map.size(); // 10
    map.remove("abc2");
    map.remove("abc7");
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << ":" << map.getValue(key) << endl; // abc2,abc7 ke cooresponding value 0 aani chahie
    }
    cout << map.size(); // 8
}