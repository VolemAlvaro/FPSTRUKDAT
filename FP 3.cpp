#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_DISEASE_LENGTH 100

// Struktur data untuk menyimpan informasi pasien
typedef struct patient {
char name[MAX_NAME_LENGTH];
char id[MAX_ID_LENGTH];
char disease[MAX_DISEASE_LENGTH];
struct patient *next;
} Patient;

// Struktur data untuk menyimpan queue antrian pelayanan
typedef struct queue {
Patient *head;
Patient *tail;
} Queue;

void enqueue(Queue *queue, char name[], char id[], char disease[]);
void dequeue(Queue *queue);
void peek(Queue queue);
void printQueue(Queue queue);

// Fungsi untuk menambahkan pasien baru ke dalam queue antrian pelayanan
void enqueue(Queue *queue, char name[], char id[], char disease[]) {
// Alokasi memori untuk pasien baru
Patient *newPatient = malloc(sizeof(Patient));
strcpy(newPatient->name, name);
strcpy(newPatient->id, id);
strcpy(newPatient->disease, disease);
newPatient->next = NULL;
// Jika queue masih kosong, maka head dan tail akan menunjuk ke pasien baru
if (queue->head == NULL) {
    queue->head = newPatient;
    queue->tail = newPatient;
}
// Jika queue sudah ada isinya, maka tambahkan pasien baru ke belakang queue
else {
    queue->tail->next = newPatient;
    queue->tail = newPatient;
}
}
// Fungsi untuk mengeluarkan pasien pertama dari queue antrian pelayanan
void dequeue(Queue *queue) {
// Jika queue sudah kosong, tidak ada yang perlu di-dequeue
if (queue->head == NULL) {
printf("Queue is empty.\n");
return;
}

// Hapus pasien pertama dari queue
Patient *temp = queue->head;
queue->head = queue->head->next;
free(temp);

// Jika queue sudah kosong setelah dequeue, reset head dan tail
if (queue->head == NULL) {
    queue->tail = NULL;
}
}
// Fungsi untuk menampilkan informasi pasien di depan queue antrian pelayanan
void peek(Queue queue) {
// Jika queue kosong, tidak ada yang perlu ditampilkan
if (queue.head == NULL) {
printf("Queue is empty.\n");
return;
}

printf("Patient at the front of the queue: \n");
printf("Name: %s\n", queue.head->name);
printf("ID: %s\n", queue.head->id);
printf("Disease: %s\n", queue.head->disease);
}

// Fungsi untuk menampilkan semua pasien yang ada di dalam queue antrian pelayanan
void printQueue(Queue queue) {
// Jika queue kosong, tidak ada yang perlu ditampilkan
if (queue.head == NULL) {
printf("Queue is empty.\n");
return;
}

// Tampilkan informasi pasien satu per satu
Patient *current = queue.head;
int i = 1;
while (current != NULL) {
    printf("Patient %d:\n", i);
    printf("Name: %s\n", current->name);
    printf("ID: %s\n", current->id);
    printf("Disease: %s\n", current->disease);
    current = current->next;
    i++;
}
}

int main() {
Queue queue;
queue.head = NULL;
queue.tail = NULL;
int choice;

do {
    printf("\nMenu:\n");
    printf("1. Add patient to queue\n");
    printf("2. Process next patient\n");
    printf("3. View next patient\n");
    printf("4. View all patients in queue\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            char name[MAX_NAME_LENGTH];
            char id[MAX_ID_LENGTH];
            char disease[MAX_DISEASE_LENGTH];
            
            printf("Enter patient name: ");
            scanf("%s", name);
            printf("Enter patient ID: ");
            scanf("%s", id);
            printf("Enter patient disease: ");
            scanf("%s", disease);
            
            enqueue(&queue, name, id, disease);
            break;
        }
        case 2: {
            dequeue(&queue);
            break;
        }
        case 3: {
            peek(queue);
            break;
        }
        case 4: {
            printQueue(queue);
            break;
        }
        case 5: {
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }
	system("cls");
	} while (choice != 5);
return 0;
}


