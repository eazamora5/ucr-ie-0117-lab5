# Universidad de Costa Rica
# IE-0117 Programacion bajo plataformas abiertas
# Profesora: Carolina Trejos
# Estudiante: Enrique Zamora Solis
# Laboratorio 5

# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = main
OBJS = main.o double_list.o

# Construccion de todo el proyecto
all: $(TARGET)

# Enlace de archivos objeto para crear ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilar main.c en main.o
main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

# Compilar double_list.c em double_list.o
double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

# Eliminacion de archivos generados
clean:
	rm -f $(TARGET) $(OBJS)
