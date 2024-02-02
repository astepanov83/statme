#include <sstream>

#include <Statme/http/Response/Formatter.h>

using namespace HTTP::Response;

Formatter::~Formatter()
{
}

void Formatter::AddTOCItem(
  bool active
  , const std::string& title
  , const std::string& link
  , const std::string& descr
)
{
  TOCItem item{};
  item.Active = active;
  item.Title = title;
  item.Link = link;
  item.Descr = descr;

  TOC.push_back(item);
}

void Formatter::AddLine(const std::stringstream& ss)
{
  AddLine(ss.str());
}

void Formatter::AddLine(const std::string& line)
{
  PRE.push_back(line);
}

TablePtr Formatter::CreateTable()
{
  TablePtr table = std::make_shared<Table>();
  Tables.push_back(table);
  return table;
}
