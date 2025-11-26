// Last updated: 26/11/2025, 22:33:17
class Node{
    int key, val;
    Node prev, next;
    Node(int k, int v){
        key = k;
        val = v;
    }
}

class LRUCache {
    private int cap;
    private Map<Integer, Node> cache;
    private Node oldest, latest;

    public LRUCache(int capacity) {
        this.cap = capacity;
        this.cache = new HashMap<>();
        this.oldest = new Node(0,0);
        this.latest = new Node(0,0);
        this.oldest.next = this.latest;
        this.latest.prev = this.oldest;
    }
    
    public int get(int key) {
        if(cache.containsKey(key)){
            Node node = cache.get(key);
            remove(node);
            insert(node);
            return node.val;
        }
        return -1;
    }

    private void remove(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void insert(Node node){
        Node prev = latest.prev;
        Node next = latest;
        prev.next = next.prev = node;
        node.next = next;
        node.prev = prev;
    }
    
    public void put(int key, int value) {
        if(cache.containsKey(key)){
            remove(cache.get(key));
        }
        Node newNode = new Node(key,value);
        cache.put(key, newNode);
        insert(newNode);
        
        if (cache.size() > cap) {
            Node lru = oldest.next;
            remove(lru);
            cache.remove(lru.key);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */