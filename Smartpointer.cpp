// Un smart pointer (puntero inteligente) es un objeto en programación que se comporta como un puntero, pero proporciona características adicionales, como gestión automática de memoria. A diferencia de los punteros crudos, los smart pointers son más seguros y ayudan a evitar problemas comunes relacionados con la gestión de memoria, como fugas de memoria.

// En C++, existen dos tipos principales de smart pointers: std::shared_ptr y std::unique_ptr.

// Elección entre std::unique_ptr y std::shared_ptr:

// Propiedad Única: Usa std::unique_ptr cuando tengas un recurso que debe ser propiedad única de un puntero. Esto ayuda a evitar referencias compartidas y simplifica la lógica de propiedad.

// Propiedad Compartida: Usa std::shared_ptr cuando necesitas compartir la propiedad de un recurso entre varios punteros y necesitas realizar copias eficientes.

// Uso General: En muchos casos, std::unique_ptr es preferible porque es más liviano y refleja de manera más clara la propiedad única del recurso. Solo utiliza std::shared_ptr si realmente necesitas la propiedad compartida y estás dispuesto a aceptar la sobrecarga asociada.

#include <iostream>
#include <memory>

class Resource
{
public:
    Resource(int value) : data(value)
    {
        std::cout << "Resource constructor. Value: " << data << std::endl;
    }

    ~Resource()
    {
        std::cout << "Resource destructor. Value: " << data << std::endl;
    }

    void display()
    {
        std::cout << "Value: " << data << std::endl;
    }

private:
    int data;
};

void withoutSmartPointer()
{
    Resource *rawPtr = new Resource(42);

    // Uso del objeto
    rawPtr->display();

    // ¡Importante! Liberación manual de memoria
    delete rawPtr;
    std::cout << "Memory manually freed." << std::endl;
}

void withUniquePointer()
{
    std::unique_ptr<Resource> smartPtr = std::make_unique<Resource>(42);

    // Uso del objeto
    smartPtr->display();

    // No se necesita liberar manualmente la memoria
    // Se libera automáticamente al salir del ámbito de smartPtr
}

// En este ejemplo, creamos una clase Resource y luego utilizamos un std::unique_ptr para gestionar la memoria de un objeto de esa clase. Veremos cómo se libera automáticamente la memoria cuando el std::unique_ptr sale del ámbito, lo cual es una ventaja significativa en comparación con la gestión manual de la memoria.

// En este ejemplo, la función withoutSmartPointer crea un objeto Resource utilizando un puntero crudo (new Resource(42)), pero luego se necesita liberar manualmente la memoria con delete. Por otro lado, la función withUniquePointer utiliza un std::unique_ptr para gestionar automáticamente la memoria. Puedes observar cómo el destructor de Resource se llama automáticamente cuando se utiliza std::unique_ptr, lo que indica que la memoria se libera de manera segura.

int main()
{
    std::cout << "Without Smart Pointer:" << std::endl;
    withoutSmartPointer();
    std::cout << std::endl;

    std::cout << "With Smart Pointer:" << std::endl;
    withUniquePointer();
    std::cout << std::endl;

    return 0;
}
