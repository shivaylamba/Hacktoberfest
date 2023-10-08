class HashMap:
    def __init__(self, size=10):
        self.size = size
        self.buckets = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        hash_key = self._hash(key)
        bucket = self.buckets[hash_key]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (key, value)
                return
        bucket.append((key, value))

    def get(self, key):
        hash_key = self._hash(key)
        bucket = self.buckets[hash_key]

        for k, v in bucket:
            if k == key:
                return v
        raise KeyError(f'Key {key} not found')

    def remove(self, key):
        hash_key = self._hash(key)
        bucket = self.buckets[hash_key]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i]
                return
        raise KeyError(f'Key {key} not found')

# Example usage:

# Create a HashMap
my_map = HashMap()

# Insert some key-value pairs
my_map.insert('apple', 'fruit')
my_map.insert('banana', 'fruit')
my_map.insert('carrot', 'vegetable')

# Get values
print(my_map.get('apple'))  # Output: 'fruit'
print(my_map.get('banana'))  # Output: 'fruit'
print(my_map.get('carrot'))  # Output: 'vegetable'

# Try to get a non-existent key (will raise KeyError)
# Uncomment the next line to see the error
# print(my_map.get('grape'))

# Remove a key
my_map.remove('apple')
# Try to get the removed key (will raise KeyError)
# Uncomment the next line to see the error
# print(my_map.get('apple'))
