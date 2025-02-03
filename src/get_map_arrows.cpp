#include "get_map_arrows.h"
#include <typeinfo>

using json = nlohmann::json;

std::vector<Arrow *> GetMapArrows()
{
  std::vector<Arrow *> arrows;

  std::ifstream f("resources/maps/ARHANT_shine.json");

  json arrows_json = json::parse(f);

  for (int i = 0; i < arrows_json["arrow_map"].size(); i++)
  {
    Arrow::beatPos pos;
    pos.bar = arrows_json["arrow_map"][i]["bar"];
    pos.beat = arrows_json["arrow_map"][i]["beat"];
    pos.tick = arrows_json["arrow_map"][i]["tick"];

    Direction dir;
    std::string json_dir = arrows_json["arrow_map"][i]["from"];
    if (json_dir == "TOP")
      dir = TOP;
    if (json_dir == "TOP_LEFT")
      dir = TOP_LEFT;
    if (json_dir == "TOP_RIGHT")
      dir = TOP_RIGHT;
    if (json_dir == "LEFT")
      dir = LEFT;
    if (json_dir == "RIGHT")
      dir = RIGHT;
    if (json_dir == "BOTTOM")
      dir = BOTTOM;
    if (json_dir == "BOTTOM_LEFT")
      dir = BOTTOM_LEFT;
    if (json_dir == "BOTTOM_RIGHT")
      dir = BOTTOM_RIGHT;
    Arrow *thisArrow = new Arrow(dir, pos);

    // std::cout << arrows_json["arrow_map"][i]["from"] << std::endl;
    arrows.push_back(thisArrow);
  }

  return arrows;
}