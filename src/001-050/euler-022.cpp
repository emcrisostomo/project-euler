#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<std::string> parse_names(std::string line);
void parse_token(const std::string& token,
                 std::vector<std::string>& tokens);
unsigned int value_of(std::string name);

// Using names.txt, a 46K text file containing over five-thousand first names,
// begin by sorting it into alphabetical order.  Then working out the
// alphabetical value for each name, multiply this value by its alphabetical
// position in the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which is
// worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.  So, COLIN
// would obtain a score of 938 × 53 = 49714.
//
// What is the total of all the name scores in the file?
//
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments: " << argc << "\n";
    return 1;
  }

  std::fstream infile(argv[1]);
  std::string line;
  std::vector<std::string> names;

  while (std::getline(infile, line))
  {
    const auto& names_in_line = parse_names(line);
    names.insert(names.end(), names_in_line.begin(), names_in_line.end());
  }

  std::sort(names.begin(), names.end());

  std::vector<unsigned int> name_values;
  std::for_each(names.begin(),
                names.end(),
                [&name_values](const auto& n)
                {
                  name_values.push_back(value_of(n));
                });

  for (auto i = 0; i < name_values.size(); ++i)
  {
    name_values[i] *= (i + 1);
  }

  unsigned int sum = std::accumulate(name_values.begin(), name_values.end(), 0u);

  std::cout << sum << "\n";
  return 0;
}

std::vector<std::string> parse_names(std::string line)
{
  // The line is a comma-separated list of quoted names.
  const std::string delimiter = ",";
  size_t pos = 0;
  std::string token;
  std::vector<std::string> tokens;

  while ((pos = line.find(delimiter)) != std::string::npos)
  {
    token = line.substr(0, pos);

    parse_token(token, tokens);
    line.erase(0, pos + delimiter.length());
  }

  parse_token(line, tokens);

  return tokens;
}

void parse_token(const std::string& token,
                 std::vector<std::string>& tokens)
{
  if (token.size() <= 2)
    throw std::runtime_error(
      std::string("Unexpected data format of token: ")
        .append(token));

  tokens.push_back(token.substr(1, token.size() - 2));
}

unsigned int value_of(std::string name)
{
  unsigned int value{0};

  std::for_each(name.begin(),
                name.end(),
                [&value](const auto& v)
                {
                  value += v - 'A' + 1;
                });

  return value;
}
