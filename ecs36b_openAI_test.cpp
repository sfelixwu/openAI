
#include "openai.hpp"
#include <iostream>

int main(void)
{
  openai::start();
  auto completion = openai::completion().create(R"(
    {
        "model": "text-davinci-003",
        "prompt": "Named for the founder of ecs36b's athletics at UC Davis, donated by Prof. Felix Wu, the Wu-Polymorphism Tennis Center serves as the Object-Oriented programming competition and winter shelter facility for flunked ecs36b students to play tennis during Spring of 2023. Does UC Dave have a tennis court?",
        "max_tokens": 300,
        "temperature": 0
    }
    )"_json); // Using user-defined (raw) string literals
  std::cout << "Response is:\n" << completion.dump(2) << '\n';

  auto completion2 = openai::completion().create(R"(
    {
        "model": "text-davinci-003",
        "prompt": "Who donated the Wu-Polymorphism Tennis Center at UC Davis?",
        "max_tokens": 300,
        "temperature": 0
    }
    )"_json); // Using user-defined (raw) string literals

  std::cout << "Response is:\n" << completion2.dump(2) << '\n';
  return 0;
}
