#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct user {
    char username[20];
    char password[20];
    char name[20];
    char lastname[20];
    char email[20];
    char phone[20];
    char address[20];
    char genderr[20];
    char age[20];
    char blood[20];
    char weight[20];
    char height[20];
};

struct user users[100];
int userCount = 0;

//////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int choice;

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("\n");
    } else {
        printf("Informacion encontrada. Leyendo informacion...\n");
        while (fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s", users[userCount].username, users[userCount].password, users[userCount].name, users[userCount].lastname, users[userCount].email, users[userCount].phone, users[userCount].address, users[userCount].genderr, users[userCount].age, users[userCount].blood, users[userCount].weight, users[userCount].height) != EOF) {
            userCount++;
        }
        fclose(file);
    }

    printf("//////////////////////////////////////\n");
    bienvenida();
    tiempoActual();
    printf("//////////////////////////////////////\n");


    while (1) {

        printf("1. Iniciar Sesion\n");
        printf("2. Registrarse\n");
        printf("3. Informacion de contacto\n");
        printf("4. Salir\n");
        printf("Escoja una opcion: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int user_index = login();
            if (user_index != -1) {
                showUserMenu(user_index);
            }
        } else if (choice == 2) {
            registerUser();
        } else if (choice == 3) {
            printf("//////////////////////////////////////\n");
            printf("Nuestros telefonos: 025456544 - 0987456321\n");
            printf("Nuestro correo: hospital@potitos.com\n");
            printf("Nuestra direccion: Av. 9 de Octubre y Av. 10 de Agosto\n");
        } else if (choice == 4) {
            break;
        } else {
            printf("Opcion no disponible.\n");
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

void bienvenida() {
    int i;
    char* texto = "BIENVENIDO A POTITOS HOSPITAL!";

    for (i = 0; i < strlen(texto); i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        usleep(90000); // espera 0.1 segundos
    }
    printf("\n");
}
void tiempoActual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Fecha y Hora Actual: %02d/%02d/%d %02d:%02d:%02d\n", tm.
    tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
void despedida() {
    int i;
    char* texto = "GRACIAS POR USAR POTITOS HOSPITAL!\nPARA MAS INFORMACION COMUNICARSE A NUESTROS NUMEROS: 025456544 - 0987456321\nUSAR MASCARILLA SALVA VIDAS!\nHASTA PRONTO!";

    for (i = 0; i < strlen(texto); i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        usleep(10000); // espera 0.1 segundos
    }
    printf("\n");
}

void showUserMenu(int user_index) {
    int choice;

    while (1) {
        printf("//////////////////////////////////////\n");
        printf("1. Revisar informacion personal\n");
        printf("2. Agendar una cita\n");
        printf("3. Ver mis citas\n");
        printf("4. Comunicarse con un doctor en este momento\n");
        printf("5. Regresar\n");
        printf("Elija una opcion: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("//////////////////////////////////////\n");
            printf("Name: %s %s\n", users[user_index].name, users[user_index].lastname);
            printf("Email: %s\n", users[user_index].email);
            printf("Phone: %s\n", users[user_index].phone);
            printf("Address: %s\n", users[user_index].address);
            printf("Gender: %s\n", users[user_index].genderr);
            printf("Age: %s\n", users[user_index].age);
            printf("Blood Type: %s\n", users[user_index].blood);
            printf("Weight: %s\n", users[user_index].weight);
            printf("Height: %s\n", users[user_index].height);
            printf("//////////////////////////////////////\n");
            printf("1. Regresar\n");
            printf("Elegir una opcion: ");
            scanf("%d", &choice);

            } else if (choice == 2) {
                //Aquí puedes agregar código para agendar una cita
            } else if (choice == 3) {
                //Aquí puedes agregar código para ver mis citas
            } else if (choice == 4) {
                printf("//////////////////////////////////////\n");
                printf("Llamando a un doctor...\n");
                printf("Por favor espere...\n");
                printf("Lo sentimos, no hay doctores disponibles en este momento.\n");
                printf("//////////////////////////////////////\n");
            } else if (choice == 5) {
                break;
            } else {
                printf("Opcion no disponible.\n");
            }
        }
    }

void registerUser() {
    char username[20];
    char password[20];
    char name[20];
    char lastname[20];
    char email[20];
    char phone[20];
    char address[20];
    char genderr[20];
    char age[20];
    char blood[20];
    char weight[20];
    char height[20];

    printf("Ingrese su Nombre de Usuario: ");
    scanf("%s", username);
    printf("Ingrese una Contrasena: ");
    scanf("%s", password);
    printf("Ingrese su nombre: ");
    scanf("%s", name);
    printf("Ingrese su apellido: ");
    scanf("%s", lastname);
    printf("Ingrese su Correo Electronico: ");
    scanf("%s", email);
    printf("Ingrese su Numero de Telefono: ");
    scanf("%s", phone);
    printf("Ingrese su Direccion: ");
    scanf("%s", address);
    printf("Ingrese su Genero: ");
    scanf("%s", genderr);
    printf("Ingrese su Edad: ");
    scanf("%s", age);
    printf("Ingrese su Tipo de Sangre: ");
    scanf("%s", blood);
    printf("Ingrese su Peso: ");
    scanf("%s", weight);
    printf("Ingrese su Altura: ");
    scanf("%s", height);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0) {
            printf("Este usuario ya se encuentra registrado.\n");
            return;
        }
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    strcpy(users[userCount].name, name);
    strcpy(users[userCount].lastname, lastname);
    strcpy(users[userCount].email, email);
    strcpy(users[userCount].phone, phone);
    strcpy(users[userCount].address, address);
    strcpy(users[userCount].genderr, genderr);
    strcpy(users[userCount].age, age);
    strcpy(users[userCount].blood, blood);
    strcpy(users[userCount].weight, weight);
    strcpy(users[userCount].height, height);
    userCount++;
    printf("Usuario registrado correctamente. Rederigiendo...\n");

    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo!\n");
        return;
    }

    //Escribir el nombre de usuario y contraseña en el archivo
    fprintf(file, "%s %s %s %s %s %s %s %s %s %s %s %s\n", username, password, name, lastname, email, phone, address, genderr, age, blood, weight, height);

    //Cerrar el archivo
    fclose(file);
}

int login() {
    char username[20];
    char password[20];
    int tries = 0;
    int user_index = -1;

    while (tries < 3) {
        printf("Ingrese su Nombre de Usuario: ");
        scanf("%s", username);
        printf("Ingrese su contrasena: ");
        scanf("%s", password);

        for (int i = 0; i < userCount; i++) {
            if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
                user_index = i;
                printf("Bienvenido/a, %s!\n", username);
                return user_index;
            }
        }

        printf("Usuario o contrasena incorrectos. Intentelo nuevamente\n");
        tries++;
    }

    printf("Muchos intentos fallidos. Regresando al menu.....\n");
    return -1;
}