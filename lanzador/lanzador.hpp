#include <vector>
#include <string>
#include <map>
#include "../json11/json11.hpp" // Asegúrate de tener esta biblioteca en tu sistema



enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno;

class Variant {
public:
    typedef Variant(*proc_type) ( const std::vector<Variant>& );
    typedef std::vector<Variant>::const_iterator iter;
    typedef std::map<std::string, Variant> map;

    variant_type type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;

    Variant(variant_type type = Symbol) : type(type) , env(0), proc(0) { }
    Variant(variant_type type, const std::string& val) : type(type), val(val) , env(0) , proc(0) { }
    Variant(proc_type proc) : type(Proc), proc(proc) , env(0) { }

    std::string to_string();
    std::string to_json_string();
    static Variant from_json_string(std::string json);
    static Variant parse_json(json11::Json job);  // Asegúrate de que esta es la definición correcta de la función
};

std::string Variant::to_string() {
    return "Not implemented";
    // Tu implementación aquí
}

std::string Variant::to_json_string() {
    return "{}";
    // Tu implementación aquí
}

Variant Variant::from_json_string(std::string sjson) {
    return Variant();
    // Tu implementación aquí
}

Variant Variant::parse_json(json11::Json job) {
    return Variant();
    // Tu implementación aquí
}