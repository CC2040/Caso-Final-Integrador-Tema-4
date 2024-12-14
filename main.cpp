#include <iostream>
#include "lanzador/lanzador.hpp"

int main() {
    // Crear instancias de Variant usando diferentes constructores
    Variant var1; // Por defecto: Symbol
    Variant var2(variant_type::Number, "42"); // Tipo Number con valor "42"
    Variant var3([](const std::vector<Variant>& args) -> Variant {
        std::cout << "Proc ejecutado con " << args.size() << " argumentos.\n";
        return Variant(variant_type::Number, "0");
    });

    // Mostrar las representaciones como string
    std::cout << "var1: " << var1.to_string() << "\n";
    std::cout << "var2: " << var2.to_string() << "\n";

    // Crear un JSON simulado y analizarlo
    std::string json_str = R"({"type": "Number", "val": "100"})";
    Variant var_from_json = Variant::from_json_string(json_str);
    std::cout << "var_from_json: " << var_from_json.to_string() << "\n";

    // Convertir una instancia de Variant a JSON
    std::cout << "var2 como JSON: " << var2.to_json_string() << "\n";

    // Ejecutar un procedimiento
    std::vector<Variant> args = { Variant(variant_type::Symbol, "x"), Variant(variant_type::Number, "10") };
    Variant result = var3.proc(args);
    std::cout << "Resultado de ejecutar var3.proc: " << result.to_string() << "\n";

    return 0;
}
