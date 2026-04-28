#include <iostream>
#include <string>
using namespace std;

// ============================================================================================================
//                                  'WAREHOUSE MANAGEMENT SYSTEM' 
//=============================================================================================================

// ----------------------- Item Class -------------------------------
// Represents a single inventory item in the system.
//  itemID: Unique ID for the item.
//  itemName: Descriptive name for the item.
//  quantity: Available stock quantity.
//  location: Physical storage location string.
// -------------------------------------------------------------------

class Item {                                  
public:                                      
    int itemID = 0;                         // Unique identifier for the item (initialized 0)
    string itemName = "";                  // Item's descriptive name (initialized empty)
    int quantity = 0;                     // Number of available units in stock (initialized 0)
    string location = "";                // Storage location for the item (initialized empty)

    // ----------------------- Default Constructor -----------------------
    // Creates an Item object with default placeholder values.
    // -------------------------------------------------------------------

    Item() = default;                       

    // ----------------------- Parameterized Constructor -----------------
    // Initialize Item with given id, name, qty and location.
    // -------------------------------------------------------------------

    Item(int id, string name, int qty, string loc) {
        itemID = id;                        // Assign id to itemID.
        itemName = name;                   // Assign name to itemName.
        quantity = qty;                   // Assign qty to quantity.
        location = loc;                  // Assign loc to location.
    }                             

    // ----------------------- display() --------------------------------
    // Prints item details: ID, Name, Stock and Location.
    // -------------------------------------------------------------------

    void display() const {           
        cout << "ID: " << itemID               
            << " | Name: " << itemName        
            << " | Stock: " << quantity      
            << " | Location: " << location  
            << endl;                       
    }                                       
};

// ----------------------- Node Class -------------------------------
// Node used by LinkedList to store Item objects.
//  data: Item stored in node.
//  next: Pointer to next Node in list.
// -------------------------------------------------------------------

class Node {                               
public:                                      
    Item data;                              // Item data stored in this node.
    Node* next = nullptr;                  // Pointer to next node (initialized nullptr)

    // ----------------------- Node Constructor -------------------------
    // Create a node storing 'item' and next set to nullptr.
    // -------------------------------------------------------------------

    Node(Item item) {                        // Constructor taking an Item.
        data = item;                        // Copy item into node data.
        next = nullptr;                    // Initialize next pointer to nullptr.
    }                                      
};

// ----------------------- Linked List -------------------------------
// Singly linked list for inventory items.
// Supports insertItem, deleteItem, updateItem, displayInventory.
// -------------------------------------------------------------------

class LinkedList {                           
private:                                     
    Node* head = nullptr;                    // Pointer to head node. (initialized nullptr)

public:                                      
    // ----------------------- insertItem --------------------------------
    // Appends a new Item at the end of the linked list.
    // -------------------------------------------------------------------

    void insertItem(Item item) {             
        Node* newNode = new Node(item);       // Allocate new node with item.
        if (head == nullptr) {               // If list is empty.
            head = newNode;                 // New node becomes head.
            return;                          
        }
        
        Node* temp = head;                    // Start traversal from head.
        while (temp->next)                   // Traverse until last node.
            temp = temp->next;              // Move to next node.
        temp->next = newNode;              // Link new node at the end.
    }                                        

    // ----------------------- deleteItem --------------------------------
    // Deletes node whose Item.itemID matches 'id'
    // Handles empty list, head deletion, middle/end deletion.
    // -------------------------------------------------------------------

    void deleteItem(int id) {                
        if (head == nullptr) {                // If list is empty,
            cout << "Inventory is empty.\n"; // Inform user list is empty.
            return;                          
        }                                    
        if (head->data.itemID == id) {         // If head node matches id.
            Node* oldHead = head;             // Store old head.
            head = head->next;               // Move head to next node.
            delete oldHead;                 // Free old head node.

            cout << "Item deleted successfully.\n"; // Inform success
            return;                          
        }

        Node* temp = head;                                   // Start traversal from head.
        while (temp->next && temp->next->data.itemID != id) // Find node before target.
            temp = temp->next;                             // Move to next node in search.

        if (!temp->next) {                    // If reached end without finding id,
            cout << "Item not found.\n";     // Inform not found.
            return;                          
        }

        Node* oldNode = temp->next;            // Node to be removed.
        temp->next = temp->next->next;        // Bypass the node in the list.
        delete oldNode;                      // Free memory of removed node.
        cout << "Item deleted successfully.\n"; 
    }                                       

    // ----------------------- updateItem --------------------------------
    // Finds item by ID and updates name, quantity and location.
    // -------------------------------------------------------------------

    void updateItem(int id, string newName, int newQty, string newLoc) {
        Node* temp = head;                           // Start traversal from head.

        while (temp) {                              // Loop until nullptr.

            if (temp->data.itemID == id) {         // If ID matches,
                temp->data.itemName = newName;    // Update itemName,
                temp->data.quantity = newQty;    // Update quantity,
                temp->data.location = newLoc;   // Update location.

                cout << "Item updated successfully.\n";
                return;                      
            }                                
            temp = temp->next;                // Move to next node.
        }        

        cout << "Item not found.\n";        // Inform if not found.
    }                                        

    // ----------------------- displayInventory ---------------------------
    // Traverses the list and calls display() for each Item.
    // -------------------------------------------------------------------

    void displayInventory() {                
        if (head == nullptr) {                // If list is empty.
            cout << "Inventory is empty.\n"; // Inform empty.
            return;                          
        }                                    
        cout << "\n------ INVENTORY LIST ------\n"; 
        Node* temp = head;                         // Start traversal from head.
        while (temp) {                            // Loop through nodes until nullptr.
            temp->data.display();                // Display item data stored in node.
            temp = temp->next;                  // Advance to next node.
        }                                      
        cout << "----------------------------\n"; 
    }                                        
};

// ----------------------- Order Class --------------------------------
// Represents a single customer order.
//  orderID: Unique order identifier.
//  customerName: Name of customer placing the order.
//  itemID: ID of item being ordered.
//  quantity: Quantity ordered.
// -------------------------------------------------------------------

class Order {                               
public:                                      
    int orderID = 0;                        // Unique order ID (initialized 0)
    string customerName = "";              // Customer name (initialized empty)
    int itemID = 0;                       // Item ID associated with order (initialized 0)
    int quantity = 0;                    // Quantity ordered (initialized 0)

    // ----------------------- Default Constructor -----------------------
    // Creates an Order with default values.
    // -------------------------------------------------------------------

    Order() = default;                      

    // ----------------------- Parameterized Constructor -----------------
    // Initialize Order with provided values.
    // -------------------------------------------------------------------

    Order(int oid, string cname, int iid, int qty) {
        orderID = oid;                        // Assign order ID.
        customerName = cname;                // Assign customer name.
        itemID = iid;                       // Assign item ID.
        quantity = qty;                    // Assign quantity.
    }                                       

    // ----------------------- display() ----------------------------
    // Prints order details: OrderID, Customer, ItemID, Quantity.
    // --------------------------------------------------------------

    void display() const {                  
        cout << "OrderID: " << orderID      
            << " | Customer: " << customerName 
            << " | ItemID: " << itemID     
            << " | Stock: " << quantity    
            << endl;                       
    }                                       
};

// ----------------------- Queue Node -----------------------------------
// Node for OrderQueue; stores an Order and pointer to next queue node.
// ----------------------------------------------------------------------

class QueueNode {                            
public:                                      
    Order data;                               // Order data held in this node.
    QueueNode* next = nullptr;               // Pointer to next queue node (initialized nullptr)

    // ----------------------- Constructor --------------------------------
    // Initializes node with given Order and next set to nullptr.
    // --------------------------------------------------------------------

    QueueNode(Order o) {                     
        data = o;                             // Copy Order into node.
        next = nullptr;                      // Initialize next pointer to nullptr.
    }                                        
};

// ----------------------- Order Queue -------------------------------
// Each order stored in QueueNode. Supports:
// enqueue(Order o): Add a new order to the end of the queue.
// dequeue(): Remove and process the order at the front of the queue.
// displayOrders(): Display all pending orders in the queue.
// -------------------------------------------------------------------

class OrderQueue {                           
private:                                     
    QueueNode* front = nullptr;               // Pointer to front node (initialized nullptr)
    QueueNode* rear = nullptr;               // Pointer to rear node (initialized nullptr)

public:                                      
    // ----------------------- enqueue ----------------------------------
    // Adds a new Order to the end of the queue.
    // -------------------------------------------------------------------

    void enqueue(Order o) {                  
        QueueNode* newNode = new QueueNode(o);           // Allocate new QueueNode with order.

        if (rear == nullptr) {                          // If queue is empty,
            front = rear = newNode;                    // Both front and rear point to new node.
            return;                          
        }                                    
        rear->next = newNode;                // Link current rear to new node.
        rear = newNode;                     // Update rear to new node.
    }                                        

    // ----------------------- dequeue -----------------------------------
    // Removes the order at the front of the queue and frees node memory.
    // -------------------------------------------------------------------

    bool dequeue(Order& processedOrder) {
        if (front == nullptr) {                // If queue is empty.
            cout << "No pending orders.\n";
            return false;                     // Indicate failure.
        }

        QueueNode* oldFront = front;          // Store current front node.
        processedOrder = oldFront->data;     // Copy data before deleting.
        front = front->next;                // Move front to next node.
        if (!front)                        // If queue is now empty.
            rear = nullptr;

        delete oldFront;                       // Free memory
        cout << "Order processed successfully.\n";
        return true;                          // Indicate success
    }

    // ----------------------- displayOrders -----------------------------
    // Traverses queue from front to rear and prints each order.
    // -------------------------------------------------------------------

    void displayOrders() {                   
        if (front == nullptr) {                         // If queue is empty,
            cout << "No pending orders.\n";            // Inform user no pending orders.
            return;                          
        }                                   

        cout << "\n------ PENDING ORDERS ------\n";
        QueueNode* temp = front;             // Start traversal from front node.
        while (temp) {                      // Loop until end of queue.
            temp->data.display();          // Display each order.
            temp = temp->next;            // Move to next queue node.
        }                                    
        cout << "-----------------------------\n";
    }                                       
}; 

// ----------------------- Stack Node ----------------------------------
// Node used by ItemStack to store Item and pointer to next stack node.
// ---------------------------------------------------------------------

class StackNode {                            
public:                                     
    Item data;                               // Item data stored in this stack node.
    StackNode* next = nullptr;              // Pointer to next stack node (initialized nullptr)
    StackNode(Item item) {                 // Constructor taking an Item.
        data = item;                      // Copy Item into node data.
        next = nullptr;                  // Initialize next pointer to nullptr.
    }                                       
};

// ----------------------- Item Stack ---------------------------------
// Simple stack for recently added/removed Items.
// push(Item): Add item to top of stack.
// pop(): Remove top item from stack.
// display(): Show stack contents.
// --------------------------------------------------------------------

class ItemStack {                            
private:                                     
    StackNode* top = nullptr;                // Pointer to top of stack (initialized nullptr)

public:                                      
    // ----------------------- push -------------------------------------
    // Push an Item onto the stack (LIFO)
    // -------------------------------------------------------------------

    void push(Item item) {                  
        StackNode* prev = nullptr;                       // Remove previous occurrence of the same itemID.
        StackNode* temp = top;                          // Start traversal from the top of the stack.
        while (temp) {                                 // Loop through the stack nodes until we reach the end (nullptr)
            if (temp->data.itemID == item.itemID) {   // Check if the current node has the same itemID as the one we are pushing.
                if (prev)                            // If there is a previous node
                    prev->next = temp->next;        // bypass the current node by linking previous node's next to current node's next.
                                                   // (removing the node from the list)
                else
                    top = temp->next;         // removed node was top.
                delete temp;                 // free memory.
                break;                      // only remove first occurrence.
            }
            prev = temp;
            temp = temp->next;
        }
        StackNode* newNode = new StackNode(item); // Allocate new StackNode with item.
        newNode->next = top;                     // Link new node to current top.
        top = newNode;                          // Update top to new node.
    }                                        

    // ----------------------- pop --------------------------------------
    // Pop the top Item from the stack and free its node.
    // -------------------------------------------------------------------

    void pop() {                             
        if (top == nullptr) {                 // If stack is empty (top == nullptr)
            cout << "Stack is empty.\n";     // Inform user stack is empty.
            return;                          
        }                                    

        StackNode* temp = top;                 // Store current top node.
        top = top->next;                      // Move top to next node
        delete temp;                         // Free removed node.

        cout << "Item removed from stack.\n";
    }                                        

    // ----------------------- display ----------------------------------
    // Display all Items currently in the stack from top to bottom.
    // -------------------------------------------------------------------

    void display() {                         
        if (top == nullptr) {                          // If stack is empty,
            cout << "Stack is empty.\n";              // Inform user stack is empty.
            return;                          
        }                                    

        cout << "\n------ RECENT ITEMS STACK ------\n";
        StackNode* temp = top;                 // Start traversal from top.
        while (temp) {                        // Loop through stack nodes.
            temp->data.display();            // Display item stored in node.
            temp = temp->next;              // Move to next node down the stack.
        }                                  
        cout << "--------------------------------\n"; 
    }                                        
};

// ------------------------ BST NODE ---------------------------------
// Node for InventoryBST that stores Item and left/right pointers.
// -------------------------------------------------------------------

class BSTNode {                              
public:                                      
    Item data;                                // Item data stored in this BST node.
    BSTNode* left = nullptr;                 // Pointer to left subtree (initialized nullptr)
    BSTNode* right = nullptr;               // Pointer to right subtree (initialized nullptr)

    BSTNode(Item item) {                   // Constructor taking an Item.
        data = item;                      // Copy item into node data.
        left = nullptr;                  // Initialize left pointer to nullptr.
        right = nullptr;                // Initialize right pointer to nullptr.
    }                                      
};

// ----------------------- Inventory BST ----------------------------------------
// Binary search tree for storing Items sorted by itemID.
// insert(Item): Adds a new item to BST while maintaining sorted order.
// displaySorted(): Prints items in order (ascending itemID).
// search(id): Finds item by ID in BST.
// update(Item): Updates an existing item in BST (removes old, inserts new).
// ------------------------------------------------------------------------------

class InventoryBST {
private:
    BSTNode* root = nullptr;  // Root node of the BST, nullptr if tree is empty

    // ----------------------- inorder ------------------------------------------------
    // Helper function for displaySorted().
    // Traverses BST in inorder (left, root, right) to print items in ascending order.
    //---------------------------------------------------------------------------------

    void inorder(BSTNode* node) {
        if (node == nullptr) 
            return;                // Base case: if node is null, do nothing.

        inorder(node->left);      // Visit left subtree,
        node->data.display();    // Display current node's item.
        inorder(node->right);   // Visit right subtree.
    }

    // ----------------------- Recursive search --------------------------
    // Internal helper to find node with given itemID starting from 'node'
    //--------------------------------------------------------------------

    BSTNode* search(BSTNode* node, int id) {
        if (node == nullptr) 
            return nullptr;                        // Not found in this path.
        if (node->data.itemID == id) 
            return node;                          // Found item.
        if (id < node->data.itemID)
            return search(node->left, id);       // Go left if ID is smaller.
        else
            return search(node->right, id);     // Go right if ID is larger.
    }

    // ----------------------- Recursive delete -------------------------
    // Removes a node with the given itemID from the BST.
    // Returns the new root of this subtree after deletion.
    //-------------------------------------------------------------------

    BSTNode* deleteNode(BSTNode* node, int id) {
        if (node == nullptr) 
            return nullptr;                             // Nothing to delete.

        if (id < node->data.itemID)                   // Target is in left subtree.
            node->left = deleteNode(node->left, id);
        else if (id > node->data.itemID)            // Target is in right subtree.
            node->right = deleteNode(node->right, id);
        else {                                    // Node to delete found.
            if (!node->left) {                   // No left child.
                BSTNode* temp = node->right;    // Replace node with right child.
                delete node;
                return temp;
            }
            else if (!node->right) {             // No right child.
                BSTNode* temp = node->left;     // Replace node with left child.
                delete node;
                return temp;
            }
            else {                               // Node has two children.
                BSTNode* succParent = node;     // Find inorder successor (smallest node in right subtree)
                BSTNode* succ = node->right;
                while (succ->left) {
                    succParent = succ;
                    succ = succ->left;
                }
                node->data = succ->data;     // Copy successor's data to this node

                // Delete the successor node
                if (succParent != node)
                    succParent->left = deleteNode(succParent->left, succ->data.itemID);
                else
                    succParent->right = deleteNode(succParent->right, succ->data.itemID);
            }
        }
        return node;  // Return updated subtree root
    }

public:
    // ----------------------- insert -----------------------------------
    // Public function to insert an item into BST.
    //-------------------------------------------------------------------

    void insert(Item item) {
        BSTNode* newNode = new BSTNode(item);    // Create a new BST node,
        if (root == nullptr) {                  // If tree is empty,
            root = newNode;                    // New node becomes root.
            return;
        }

        BSTNode* current = root;                 // Start from root,
        BSTNode* parent = nullptr;              // Track parent node,
        while (current) {                      // Traverse to find correct spot.
            parent = current;
            if (item.itemID < current->data.itemID)
                current = current->left;                 // Go left if smaller.
            else
                current = current->right;               // Go right if larger.
        }

        if (item.itemID < parent->data.itemID)        // Attach new node as child of parent.
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    
    void deleteItem(int id) {
            root = deleteNode(root, id); // Start deletion from the root.
    }


    // ----------------------- displaySorted ----------------------------
    // Public function to display BST in sorted order (ascending itemID)
    //-------------------------------------------------------------------

    void displaySorted() {
        if (root==nullptr) { 
            cout << "BST is empty.\n"; return; 
        }
        cout << "\n------ SORTED INVENTORY (BST) ------\n";
        inorder(root);                          // Call recursive inorder helper.
        cout << "------------------------------------\n";
    }

    // ----------------------- Search public wrapper --------------------
    // Find and return a pointer to the node with given ID.
    //-------------------------------------------------------------------

    BSTNode* search(int id) {
        return search(root, id);
    }

    // ----------------------- Update item in BST -----------------------
    // Updates an existing item in BST:
    // 1. Delete the old node with same ID
    // 2. Insert the new (updated) item
    //-------------------------------------------------------------------

    void update(Item item) {
        root = deleteNode(root, item.itemID);    // Remove old node.
        insert(item);                           // Insert updated node.
    }
};

// ----------------------- Warehouse Grid --------------------------------
// Represents a 2D grid of Item pointers for physical layout of warehouse.
// placeItem(r,c,item*): Place or replace an Item pointer at grid cell.
// DisplayGrid(): Prints the grid with item names or "Empty"
// Destructor frees allocated Item pointers and grid arrays.
// -----------------------------------------------------------------------

class WarehouseGrid {                        
private:                                     
    int rows;                                // Number of rows in grid.
    int cols;                               // Number of columns in grid.
    Item*** grid;                          // 2D array (rows x cols) of Item* pointers.

public:                                      
    // ----------------------- Constructor --------------------------------
    // Allocates grid arrays and initializes each cell to nullptr.
    // -------------------------------------------------------------------

    WarehouseGrid(int r, int c) {            
        rows = r;                                   // Assign rows.
        cols = c;                                  // Assign cols.

        grid = new Item * *[rows];               // Allocate array of row pointers

        for (int i = 0; i < rows; i++) {       // For each row,
            grid[i] = new Item * [cols];      // Allocate array of column pointers.

            for (int j = 0; j < cols; j++)  // For each column in row
                grid[i][j] = nullptr;      // Initialize cell to nullptr.
        }                                    
    }                                        

    // ----------------------- Destructor ---------------------------------
    // Deletes all Item pointers stored in grid and frees arrays.
    // -------------------------------------------------------------------

    ~WarehouseGrid() {                       
        for (int i = 0; i < rows; i++) {       // For each row,
            for (int j = 0; j < cols; j++) {  // For each cell in row,
                delete grid[i][j];           // Delete Item pointer.
            }                                
            delete[] grid[i];              // Delete columns array for this row.
        }                                    
        delete[] grid;                   // Delete row pointers array.
    }                                        

    // ----------------------- placeItem --------------------------------------
    // Place an Item pointer at position (r, c). Deletes existing Item* first.
    // ------------------------------------------------------------------------

    void placeItem(int r, int c, Item* item) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {    // Check bounds,
            cout << "Invalid grid position.\n";           // Inform invalid position.
            return;                          
        }                                    
        delete grid[r][c];                              // Delete existing Item pointer at cell (if any)
        grid[r][c] = item;                             // Assign new Item pointer to cell.
    }                                        

    // ----------------------- displayGrid -----------------------------------
    // Prints the grid: itemName for occupied cells or "Empty" for nullptr.
    // -----------------------------------------------------------------------

    void displayGrid() {                     
        cout << "\n------ WAREHOUSE GRID ------\n";
        for (int i = 0; i < rows; i++) {                     // For each row,
            for (int j = 0; j < cols; j++) {                // For each column in row,
                if (grid[i][j])                            // If cell contains an Item pointer,
                    cout << grid[i][j]->itemName << "\t"; // Print itemName and tab.
                else
                    cout << "Empty\t";                  // Print "Empty" if nullptr.
            }                                
            cout << endl;                   
        }                                    
        cout << "----------------------------\n";
    }                                        
};

// ----------------------- MAIN FUNCTION --------------------------------
// Provides simple console menu to interact with LinkedList inventory,
// BST sorted view, WarehouseGrid, OrderQueue and ItemStack.
// -----------------------------------------------------------------------

int main() {                                 
    LinkedList inventory;                     // Create linked list inventory instance.
    ItemStack recentItems;                   // Create stack for recent items.
    InventoryBST bstInventory;              // Create BST for sorted inventory.
    WarehouseGrid warehouse(3, 3);         // Create 3x3 warehouse grid instance.
    OrderQueue orders;                    // Create order queue instance.

    int choice;                         // Variable to store user menu choice.

    while (true) {                    // Loop menu until user exits.
        cout << "\n====== WAREHOUSE MANAGEMENT ======\n"; 
        cout << "1. Add Item\n";                               // Option 1: Add Item.
        cout << "2. Delete Item\n";                           // Option 2: Delete Item.
        cout << "3. Update Item\n";                          // Option 3: Update Item.
        cout << "4. Display Inventory (Linked List)\n";     // Option 4: Display linked list.
        cout << "5. Display Inventory (BST Sorted)\n";     // Option 5: Display BST sorted.
        cout << "6. Display Warehouse Grid\n";            // Option 6: Display grid.
        cout << "7. Add Order\n";                        // Option 7: Add order to queue.
        cout << "8. Process Order\n";                   // Option 8: Dequeue/process order.
        cout << "9. Display Orders\n";                 // Option 9: Show pending orders.
        cout << "10. Display Recent Items (Stack)\n"; // Option 10: Show recent items stack.
        cout << "11. Search Item (BST)\n";           // Option 11 for search.
        cout << "0. Exit\n";                        // Option 0: Exit program.

        cout << "Enter your choice: ";            // Prompt for user choice.

        cin >> choice;                          // Read user input into choice.

        if (choice == 0)                      // If user chose 0
            break;                           // Exit the menu loop.

        switch (choice) {                  // Switch on user's choice.

        case 1: {                            // Case 1: Add Item
            int id, qty;                    // Local variables for id and quantity.
            string name, loc;              // Local strings for name and location.

            cout << "Enter Item ID: ";        
            cin >> id;                       // Read Item ID.

            cout << "Enter Item Name: ";      
            cin >> ws;                       // Clear leading whitespace before getline
            getline(cin, name);             // Read full line for item name.

            cout << "Enter Quantity: ";       
            cin >> qty;                     // Read quantity.

            cout << "Enter Location: ";       
            cin >> ws;                       // Clear whitespace before getline.
            getline(cin, loc);              // Read full line for location.


            Item newItem(id, name, qty, loc);         // Construct new Item.

            inventory.insertItem(newItem);           // Insert into linked list inventory.
            recentItems.push(newItem);              // Push into recent items stack.
            bstInventory.insert(newItem);          // Insert into BST for sorted view.

            cout << "Item added successfully.\n"; // Inform user of success.
            break;                           
        }                                    

        case 2: {                                       // Case 2: Delete Item.
            int id;                                    // Local variable for id.

            cout << "Enter Item ID to delete: ";      
            cin >> id;                               // Read id from user.

            inventory.deleteItem(id);               // Delete item from linked list.
            recentItems.push(Item(id, "", 0, "")); // Push a placeholder to recent stack.
            bstInventory.deleteItem(id);          // delete from BST.
            break;                         
        }                                    

        case 3: {                            // Case 3: Update Item
            int id, qty;                    // Local variables for id and quantity.
            string name, loc;              // Local strings for name and location.

            cout << "Enter Item ID to update: ";
            cin >> id;                       // Read item ID

            cout << "Enter New Name: ";

            cin >> ws;                       // Clear whitespace before getline.
            getline(cin, name);             // Read new name.

            cout << "Enter New Quantity: ";   
            cin >> qty;                      // Read new quantity.

            cout << "Enter New Location: ";  
            cin >> ws;                        // Clear whitespace before getline.
            getline(cin, loc);               // Read new location.

            inventory.updateItem(id, name, qty, loc);           // Update item in linked list.
            recentItems.push(Item(id, name, qty, loc));        // push updated item to stack.
            bstInventory.update(Item(id, name, qty, loc));    // Update BST (delete old + insert new)
            break;                           
        }                                    

        case 4:                                  // Case 4: Display Inventory (Linked List)
            inventory.displayInventory();       // Call linked list display method.
            break;                           

        case 5:                               // Case 5: Display Inventory (BST Sorted)
            bstInventory.displaySorted();    // Call BST sorted display.
            break;                           

        case 6:                            // Case 6: Display Warehouse Grid
            warehouse.displayGrid();      // Call grid display method.
            break;                           

        case 7: {                              // Case 7: Add Order
            int orderID, itemID, orderQty;    // Local variables for order details.
            string customer;                 // Local string for customer name.

            cout << "Enter Order ID: ";      
            cin >> orderID;                  // Read order ID

            cout << "Enter Customer Name: ";
            cin >> ws;                        // Clear whitespace before getline.
            getline(cin, customer);          // Read full line for customer.

            cout << "Enter Item ID: ";        
            cin >> itemID;                   // Read item ID.

            cout << "Enter Quantity: ";      
            cin >> orderQty;                 // Read order quantity.

            orders.enqueue(Order(orderID, customer, itemID, orderQty)); // Enqueue new order.
            break;                           
        }                                    

        case 8: {
            Order o;
            if (!orders.dequeue(o)) 
                break;

            // Search item in BST
            BSTNode* node = bstInventory.search(o.itemID);
            if (node == nullptr) {
                cout << "Item not found in inventory.\n";
                break;
            }

            if (node->data.quantity < o.quantity) {
                cout << "Not enough stock available.\n";
                break;
            }

            // Reduce quantity
            node->data.quantity -= o.quantity;

            // Sync updates
            inventory.updateItem(
                node->data.itemID,
                node->data.itemName,
                node->data.quantity,
                node->data.location
            );

            bstInventory.update(node->data);

            cout << "Order processed and inventory updated.\n";
            break;
        }

        case 9:                               // Case 9: Display Orders
            orders.displayOrders();          // Display pending orders.
            break;                           

        case 10:                              // Case 10: Display Recent Items (Stack)
            recentItems.display();           // Display items in stack.
            break;

        case 11: {
            int id;
            cout << "Enter Item ID to search: ";
            cin >> id;

            BSTNode* found = bstInventory.search(id);  // Search BST
            if (found) {
                cout << "Item found:\n";
                found->data.display();                // Display item details
            }
            else {
                cout << "Item not found in BST.\n";
            }
            break;
        }

        default:                                     // Default: invalid choice.
            cout << "Invalid choice. Try again.\n"; // Inform user of invalid input.
        }                                    
    }                                        
    cout << "Exiting Warehouse Management System.\n"; // Exit message.

    return 0;                                
}                                            