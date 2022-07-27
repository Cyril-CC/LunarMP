//
// Created by Cyril on 2022/7/26.
//

#include "ModelNesting.h"
#include <fstream>

namespace lunarmp {

bool ModelNesting::readFile(std::string input_file) {
    std::ifstream file;
    file.open(input_file, std::ios::in);

    if (!file.is_open()) {
        std::cout << "empty!\n";
        return false;
    }

    std::string str_line;

    while (getline(file, str_line)) {
        if (str_line.empty()) {
            continue;
        }
        std::cout << str_line << "\n";
    }
    return true;
}

void ModelNesting::writeFile(std::string output_file) {
    rapidjson::Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType& part_allocator = doc.GetAllocator();
    rapidjson::Value res(rapidjson::kArrayType);

    for (Part part : result_parts) {
        doc.AddMember("id", part.model_id, doc.GetAllocator());

        rapidjson::Value poly(rapidjson::kArrayType);
        const Polygon_2 p = part.rotate_polygon;
        for (VertexIterator vi = p.vertices_begin(); vi != p.vertices_end(); ++vi) {
            rapidjson::Value v(rapidjson::kObjectType);
            v.AddMember("x", (*vi).x(), part_allocator);
            v.AddMember("y", (*vi).y(), part_allocator);
            poly.PushBack(v, part_allocator);
        }
        doc.AddMember("in_place", part.inPlace, doc.GetAllocator());
    }
}

void ModelNesting::modelNesting(std::string input_file, std::string output_file, DataGroup& data_group) {
    // get data_group
//    readFile(input_file);
//    startNFP();
//    writeFile(output_file);
}

}
