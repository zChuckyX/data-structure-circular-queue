#include <stdio.h>

#define MAX_QUEUE 100 // จำกัดขนาด Queue MAX อยู่ที่ 100
#define MIN_QUEUE 1 // จำกัดขนาด Queue MIN อยู่ที่ 1

int SIZE, choice, front, rear; // ประกาศตัวแปร ประเภท int 

int select_type(); // อ่านฟังก์ชั่น select_type

void singly_queue(); // อ่านฟังก์ชั่น singly_queue
void double_queue(); // อ่านฟังก์ชั่น double_queue

int isEmpty(); // อ่านฟังก์ชั่น isEmpty
int isFull(); // อ่านฟังก์ชั่น isFull

// ฟังก์ชั่นหลัก 
int main() {
    while (1) {
        int choice = select_type();
    
        if (choice == 1) {
            singly_queue();
        } else if (choice == 2) {
            double_queue();
        } else {
            printf("Close Program\n");
            break;
        }
    }
    
    return 0;
}

// ฟีงก์ชั่นเลือกรูปแบบ Queue ที่ต้องการใช้งาน
int select_type() {
    int choice;
    
    while (1) {
        printf("--- Queue Type Options ---\n");
        printf(" 1.Singly Circular Queue\n");
        printf(" 2.Double Circular Queue\n");
        printf(" 3.Exit Program\n");
        printf("--------------------------\n");
        printf("Enter Here : ");
        
        if (scanf("%d", &choice) != 1) {
            printf("[ERROR] Please enter an integer.\n");
            
            while (getchar() != '\n'); // เคลียร์ Buffer
        } else {
            if (choice > 0 && choice < 4) {
                break;
            } else {
                printf("[ERROR] Please Enter 1-3\n\n");
            }
        }
    }
    
    return choice;
}

// ฟังก์ชั่นของ Singly Circular Queue 
void singly_queue() {
    front = -1, rear = -1; // กำหนดให้ front, rear เป็น -1
    
    while (1) {
        printf("[Queue] Enter Size : ");
        
        if (scanf("%d", &SIZE) != 1) {
            printf("[ERROR] Please enter an integer.\n");
            
            while (getchar() != '\n');  // เคลียร์ Buffer
        } else {
            if (SIZE > MAX_QUEUE) {
                printf("[ERROR] MAXIMUM SIZE %d\n", MAX_QUEUE);
            } else if (SIZE < MIN_QUEUE) {
                printf("[ERROR] MINIMUM SIZE %d\n", MIN_QUEUE);
            } else {
                break;
            }
        }
    }

    int singly_arrays[SIZE]; // สร้าง Array ของ Singly Queue
    
    // ฟังก์ชั่นการเพิ่มค่าเข้าใน Queue
    void enQueue() {
        // การตรวจสอบภายใน Queue เต็มหรือไม่ 
        if (!isFull()) {
            int value;
            printf("[Queue] Enter Value : ");
            
            while (scanf("%d", &value) != 1) {
                printf("[ERROR] Please enter an integer.\n");
                
                while (getchar() != '\n'); // เคลียร์ Bufferz
            }
            
            // เมื่อเพิ่มค่าครั้งแรกของ Queue จะให้ front จาก -1 เป็น 0
            if (front == -1) {
                front = 0;
            }
            
            rear = (rear + 1) % SIZE; // คำสั่งการเลื่อนตำแหน่งของ rear
            singly_arrays[rear] = value; // คำสั่งการเพิ่มค่าใน Queue
            
            printf("[Queue] Added %d to the queue\n\n", value);
        } else {
            printf("[Queue] Queue is full!\n\n");
        }
    }
    
    // ฟังก์ชั่นการลบค่าออกจาก Queue
    void deQueue() {
        // การตรวจสอบภายใน Queue ว่างเปล่าหรือไม่
        if (!isEmpty()) {
            printf("[Queue] Deleted %d from the queue\n\n", singly_arrays[front]);
            
            if (front == rear) {
                front = rear = -1;  // คำสั่งเมื่อมีการลบค่าของจาก Queue ค่าสุดท้าย ให้เปลื่ยน front, rear เป็น -1
            } else {
                front = (front + 1) % SIZE; // คำสั่งการเลื่อนตำแหน่งของ front
            }
        } else {
            printf("[Queue] Queue is empty!\n\n");
        }
    }
    
    // ฟังก์ชั่นการแสดงผลค่าภายใน Queue
    void display() {
        // การตรวจสอบภายใน Queue ว่างเปล่าหรือไม่
        if (isEmpty()) {
            printf("[Queue] Queue is empty!\n\n");
        } else {
            printf("[Queue] Elements: ");
            
            int i = front;
            
            // while loop สำหรับแสดงผลค่าทั้งหมดภายใน Queue
            while (i != rear) {
                printf("%d --> ", singly_arrays[i]);
                i = (i + 1) % SIZE;
            }
            
            printf("%d\n\n", singly_arrays[rear]); // แสดงผลค่าสุดท้าย
        }
    }

    while (1) {
        printf("--- Singly Circular Queue ---\n");
        printf(" SIZE OF QUEUE = %d\n", SIZE);
        printf(" Front = %d, Rear = %d\n", front, rear);
        printf(" 1.Enqueue\n");
        printf(" 2.Dequeue\n");
        printf(" 3.Display\n");
        printf(" 4.Exit\n");
        printf("-----------------------------\n");

        while (1) {
            printf("[Queue] Enter Options : ");
            
            if (scanf("%d", &choice) != 1) {
                printf("[ERROR] Please enter an integer.\n");
                
                while (getchar() != '\n'); 
            } else {
                if (choice > 0 && choice < 5) {
                    break;
                } else {
                    printf("[ERROR] Please enter 1-4\n");
                }
            }
        }

        if (choice == 1) { 
            enQueue();
        } else if (choice == 2) { 
            deQueue();
        } else if (choice == 3) { 
            display();
        } else if (choice == 4) { 
            printf("\n");
            break;
        }
    }
}

// ฟังก์ชั่นของ Double Circular Queue 
void double_queue() {
    int choice2;
    front = -1, rear = -1; // กำหนดให้ front, rear เป็น -1

    while (1) {
        printf("[Queue] Enter Size : ");
        
        if (scanf("%d", &SIZE) != 1) {
            printf("[ERROR] Please enter an integer.\n");
            
            while (getchar() != '\n'); 
        } else {
            if (SIZE > MAX_QUEUE) {
                printf("[ERROR] MAXIMUM SIZE %d\n", MAX_QUEUE);
            } else if (SIZE < MIN_QUEUE) {
                printf("[ERROR] MINIMUM SIZE %d\n", MIN_QUEUE);
            } else {
                break;
            }
        }
    }

    int double_arrays[SIZE]; // สร้าง Array ของ Double Singly
    
    // ฟังก์ชั่นการเพิ่มค่าเข้าใน Queue จากด้านหน้า
    void enqueueFront() {
        // การตรวจสอบภายใน Queue เต็มหรือไม่
        if (!isFull()) {
            int value;
            
            printf("[Queue] Enter Value : ");
            
            while (scanf("%d", &value) != 1) {
                printf("[ERROR] Please enter an integer.\n");
                
                while (getchar() != '\n'); // เคลียร์ Buffer
            }
            
            // เมื่อเพิ่มค่าครั้งแรกของ Queue จะให้ front, rear จาก -1 เป็น 0
            if (rear == -1) {
                rear = front = 0;
            } else {
                if (front == 0) {
                    front = SIZE - 1; 
                } else {
                    front--; // คำสั่งการเลื่อนตำแหน่งของ front 
                }
            }
            
            double_arrays[front] = value; // คำสั่งการเพิ่มค่าใน Queue จากด้านหน้า
            
            printf("[Queue] Added %d to the queue\n\n", value);
        } else {
            printf("[Queue] Queue is full!\n\n");
        }
    }
    
    // ฟังก์ชั่นการเพิ่มค่าเข้าใน Queue จากด้านหลัง
    void enqueueRear() {
        // การตรวจสอบภายใน Queue เต็มหรือไม่
        if (!isFull()) {
            int value;
            
            printf("[Queue] Enter Value : ");
            
            while (scanf("%d", &value) != 1) {
                printf("[ERROR] Please enter an integer.\n");
                
                while (getchar() != '\n'); // เคลียร์ Buffer
            }
            
            // เมื่อเพิ่มค่าครั้งแรกของ Queue จะให้ front จาก -1 เป็น 0
            if (front == -1) {
                front = 0;
            }
            
            rear = (rear + 1) % SIZE; // คำสั่งการเลื่อนตำแหน่งของ rear 
            double_arrays[rear] = value; // คำสั่งการเพิ่มค่าใน Queue จากด้านหลัง
            
            printf("[Queue] Added %d to the queue\n\n", value);
        } else {
            printf("[Queue] Queue is full!\n\n");
        }
    }
    
    // ฟังก์ชั่นการลบค่าออกจาก Queue จากด้านหน้า
    void dequeueFront() {
        // การตรวจสอบภายใน Queue ว่างเปล่าหรือไม่
        if (!isEmpty()) {
            printf("[Queue] Deleted %d from the queue\n\n", double_arrays[front]);
            
            // คำสั่งเมื่อมีการลบค่าของจาก Queue ค่าสุดท้าย ให้เปลื่ยน front, rear เป็น -1
            if (front == rear) {
                front = rear = -1;
            } else {
                if (front == SIZE - 1) {
                    front = 0;
                } else {
                    front++; //คำสั่งการเลื่อนตำแหน่งของ front
                }
            }
        } else {
            printf("[Queue] Queue is empty!\n\n");
        }
    }
    
    // ฟังก์ชั่นการลบค่าออกจาก Queue จากด้านหลัง
    void dequeueRear() {
        // การตรวจสอบภายใน Queue ว่างเปล่าหรือไม่
        if (!isEmpty()) {
            printf("[Queue] Deleted %d from the queue\n\n", double_arrays[rear]);
            
            // คำสั่งเมื่อมีการลบค่าของจาก Queue ค่าสุดท้าย ให้เปลื่ยน front, rear เป็น -1
            if (rear == front) {
                rear = front = -1;
            } else {
                if (rear == 0) {
                    rear = SIZE - 1;
                } else {
                    rear--; //คำสั่งการเลื่อนตำแหน่งของ rear
                }
            }
        } else {
            printf("[Queue] Queue is empty!\n\n");
        }
    }
    
    // ฟังก์ชั่นการแสดงผลค่าภายใน Queue จากหน้า
    void displayFront() {
        // การตรวจสอบภายใน Queue ว่างเปล่าหรือไม่
        if (isEmpty()) {
            printf("[Queue] Queue is empty!\n\n");
        } else {
            printf("[Queue] Elements: ");
            
            int i = front;
            
            // while loop สำหรับแสดงผลค่าทั้งหมดภายใน Queue
            while (i != rear) {
                printf("%d --> ", double_arrays[i]);
                i = (i + 1) % SIZE;
            }
            
            printf("%d\n\n", double_arrays[rear]); // แสดงผลค่าสุดท้าย
        }
    }
    
    // ฟังก์ชั่นการแสดงผลค่าภายใน Queue จากหลัง
    void displayRear() {
        // การตรวจสอบภายใน Queue ว่างเปล่าหรือไม่
        if (isEmpty()) {
            printf("[Queue] Queue is empty!\n\n");
        } else {
            printf("[Queue] Elements: ");
            
            int i = rear;
            
            // while loop สำหรับแสดงผลค่าทั้งหมดภายใน Queue
            while (i != front) {
                printf("%d --> ", double_arrays[i]);
                if (i == 0) {
                    i = SIZE - 1;
                } else {
                    i--; //คำสั่งการเลื่อนตำแหน่งของ rear
                }
            }
            
            printf("%d\n\n", double_arrays[front]); // แสดงผลค่าสุดท้าย
        }
    }

    while (1) {
        printf("--- Double Circular Queue ---\n");
        printf(" SIZE OF QUEUE = %d\n", SIZE);
        printf(" Front = %d, Rear = %d\n", front, rear);
        printf(" 1.Enqueue\n");
        printf(" 2.Dequeue\n");
        printf(" 3.Display\n");
        printf(" 4.Exit\n");
        printf("-----------------------------\n");

        while (1) {
            printf("[Queue] Enter Options : ");
            
            if (scanf("%d", &choice) != 1) {
                printf("[ERROR] Please enter an integer.\n");
                
                while (getchar() != '\n'); 
            } else {
                if (choice > 0 && choice < 5) {
                    break;
                } else {
                    printf("[ERROR] Please enter 1-4\n");
                }
            }
        }
        
        if (choice == 1) {
            printf("--- Double Circular Queue ---\n");
            printf(" Enqueue Options\n");
            printf("  1.Front Enqueue\n");
            printf("  2.Rear Enqueue\n");
            printf("  3.Back\n");
            printf("-----------------------------\n");
            
            while (1) {
                printf("[Queue] Enter Options : ");
                
                if (scanf("%d", &choice2) != 1) {
                    printf("[ERROR] Please enter an integer.\n");
                    
                    while (getchar() != '\n'); // เคลียร์ Buffer
                } else {
                    if (choice2 > 0 && choice2 < 4) {
                        break;
                    } else {
                        printf("[ERROR] Please enter 1-4\n");
                    }
                }
            }
            
            if (choice2 == 1) {
                enqueueFront();
            } else if (choice2 == 2) {
                enqueueRear();
            } 
        } else if (choice == 2) {
            printf("--- Double Circular Queue ---\n");
            printf(" Dequeue Options\n");
            printf("  1.Front Dequeue\n");
            printf("  2.Rear Dequeue\n");
            printf("  3.Back\n");
            printf("-----------------------------\n");
            
            while (1) {
                printf("[Queue] Enter Options : ");
                
                if (scanf("%d", &choice2) != 1) {
                    printf("[ERROR] Please enter an integer.\n");
                    
                    while (getchar() != '\n'); // เคลียร์ Buffer
                } else {
                    if (choice2 > 0 && choice2 < 4) {
                        break;
                    } else {
                        printf("[ERROR] Please enter 1-4\n");
                    }
                }
            }
            
            if (choice2 == 1) {
                dequeueFront();
            } else if (choice2 == 2) {
                dequeueRear();
            }
        } else if (choice == 3) {
            printf("--- Double Circular Queue ---\n");
            printf(" Display Options\n");
            printf("  1.Front Display\n");
            printf("  2.Rear Display\n");
            printf("  3.Back\n");
            printf("-----------------------------\n");
            
            while (1) {
                printf("[Queue] Enter Options : ");
                
                if (scanf("%d", &choice2) != 1) {
                    printf("[ERROR] Please enter an integer.\n");
                    
                    while (getchar() != '\n'); // เคลียร์ Buffer
                } else {
                    if (choice2 > 0 && choice2 < 4) {
                        break;
                    } else {
                        printf("[ERROR] Please enter 1-4\n");
                    }
                }
            }
            
            if (choice2 == 1) {
                displayFront();
            } else if (choice2 == 2) {
                displayRear();
            }
        } else {
            printf("\n");
            break;
        }
    }
}

// ฟังก์ชั่นตรวจสอบการว่างเปล่าของ Queue
int isEmpty() {
    return (front == -1);
}

// ฟังก์ชั่นการตรวจสอบการเต็มของ Queue
int isFull() {
    return ((rear + 1) % SIZE == front);
}
