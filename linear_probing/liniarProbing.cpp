#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

// HashEntry Class Declaration
class HashEntry
{
public:
    int key;
    int value;
    int index;
    HashEntry(int key, int value, int index)
    {
        this->key = key;
        this->value = value;
        this->index = index;
    }
};

// HashMap Class Declaration
class HashMap
{
private:
    HashEntry **htable;
    int TableSize;
    int count;

public:
    HashMap(int T_S)
    {
        TableSize = T_S;
        count = 0;
        htable = new HashEntry *[TableSize];
        for (int i = 0; i < TableSize; i++)
            htable[i] = NULL;
    }
    ~HashMap()
    {
        delete[] htable;
    }
    // Hash Function
    int HashFunc(int key, int i = 0)
    {
        if (i == 0)
            return key % TableSize;
        else
            return ((key % TableSize) + i) % TableSize;
    }
    // Insert Element at a key
    void Insert(int key, int value)
    {
        int hash_val = HashFunc(key);
        if (htable[hash_val] == NULL)
        {
            htable[hash_val] = new HashEntry(key, value, hash_val);
            count = count + 1;
            return;
        }
        // when there is collision
        int i = 1;
        while (htable[hash_val] != NULL)
        {
            if (hash_val + 1 >= TableSize)
            {
                htable = new HashEntry *[TableSize * 2];
                TableSize = TableSize * 2;
            }
            hash_val = HashFunc(key, i++);
        }
        htable[hash_val] = new HashEntry(key, value, hash_val);
        count = count + 1;
    }
    // Remove Element at a key
    void Remove(int key)
    {
        int hash_val = HashFunc(key);
        HashEntry *entry = htable[hash_val];
        if (entry->key == key)
        {
            count--;
            delete entry;
            htable[hash_val] = NULL;
            cout << "\nElement Deleted" << endl;
            return;
        }
        // when there is collision
        int i = 1;
        while (entry->key != key)
        {
            hash_val = HashFunc(key, i++);
            entry = htable[hash_val];
        }
        count--;
        delete entry;
        htable[hash_val] = NULL;
        cout << "\nElement Deleted" << endl;
    }
    // Search Element at a key
    bool Search(int key)
    {
        int hash_val = HashFunc(key);
        HashEntry *entry = htable[hash_val];
        if (entry->key == key)
        {
            cout << "\n element exist in index = " << hash_val << " value = " << entry->value << endl;
            return true;
        }
        // when there is collision
        else if (entry != NULL)
        {
            int i = 1;
            while (entry->key != key)
            {
                hash_val = HashFunc(key, i++);
                entry = htable[hash_val];
            }
            cout << "\n element exist in index = " << hash_val << " value = " << entry->value << endl;
            return true;
        }
        return false;
    }
    // Search Element at a key
    void print()
    {
        if (count == 0)
            return;
        int i = 0;
        cout << "\n-----------------------------------------" << endl;
        HashEntry *entry = htable[i];
        while (i < TableSize)
        {
            if (entry != NULL)
            {
                cout << "[key= " << entry->key << " , value = " << entry->value << "]  --> insered at index = " << entry->index << endl;
            }
            entry = htable[++i];
        }
    }
};
// Main Contains Menu
int main()
{
    HashMap hash(10);
    // insert
    hash.Insert(1, 10);
    hash.Insert(2, 15);
    hash.Insert(3, 2);
    hash.Insert(4, 2);
    hash.Insert(10, 7);
    hash.Insert(11, 77);
    // print
    hash.print();
    // search

    if (hash.Search(1) == false)
        cout << " No element found at key " << 1 << endl;
    // remove
    hash.Remove(1);
    // print
    hash.print();

    return 0;
}
