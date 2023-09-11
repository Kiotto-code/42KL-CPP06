#include <iostream>
#include <cstdint>

struct Data {
    int value;
	std::string str;
};
// class Data {
// public:
//     int value;
// 	std::string str;

// 	Data(void);
//     Data(int val) : value(val) {};
//     Data(std::string const &val) : str(val) {};
// };

class Serializer {
public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

// int main() {
//     // Create a Data object
//     Data* originalPtr = new Data(42);

//     // Serialize the pointer
//     uintptr_t serializedPtr = Serializer::serialize(originalPtr);

//     // Deserialize the serialized pointer
//     Data* deserializedPtr = Serializer::deserialize(serializedPtr);

//     // Check if the deserialized pointer is equal to the original pointer
//     if (originalPtr == deserializedPtr) {
//         std::cout << "Serialization and deserialization successful!" << std::endl;
//         std::cout << "Original Value: " << originalPtr->value << std::endl;
//     } else {
//         std::cout << "Serialization and deserialization failed!" << std::endl;
//     }

//     // Clean up allocated memory
//     delete originalPtr;

//     return 0;
// }

int main()
{
	Serializer s = Serializer();
	Data data;
	Data* dataPtr;
	uintptr_t raw;

	data.str = "test_data";
	data.value = 42;
	std::cout << &data << std::endl;
	std::cout << data.str << std::endl;
	std::cout << data.value << std::endl;

	raw = s.serialize(&data);
	std::cout << raw << std::endl;

	dataPtr = s.deserialize(raw);
	std::cout << dataPtr << std::endl;
	std::cout << dataPtr->str << std::endl;
	std::cout << dataPtr->value << std::endl;
}
