#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "max_heap.hpp"
#include "string_bst.hpp"

static std::string to_string(std::vector<std::string> const& vec){
  std::string output;
  output += "{";
  bool first = true;
  for(auto const& str: vec){
    if(!first){
      output += ", ";
    }
    output += str;
    first = false;
  }
  output += "}";
  return output;
}

static std::string to_string(std::vector<text_item> items){
  std::ostringstream out;
  out << "{";
  bool first = true;
  for(auto const& item: items){
    if(!first){
      out << ",";
    }
    out << item;
  }
  out << "}";
  return out.str();
}

template<typename Container, typename Comparator, typename Fn>
void permute(Container items, Comparator comp, Fn fn){
  std::sort(items.begin(), items.end(), comp);
  auto sorted_items = items;
  do{
    fn(items, sorted_items);
  }while(std::next_permutation(items.begin(), items.end(), comp));
}

void test_heap_permutations_insert(std::vector<text_item> items){
  permute(items, [](text_item const& a, text_item const& b){
    return a.freq > b.freq;
  }, [](std::vector<text_item> const& items, std::vector<text_item> const& sorted_items){
    SECTION(to_string(items)){
      max_heap hp(items.size());
      CHECK_THROWS_AS(hp.top(), std::logic_error);
      text_item max{"aaaa", std::numeric_limits<int>::lowest()};
      for(auto const& item: items){
        hp.insert(item);
        if(item.freq > max.freq){
          max = item;
        }
        CHECK(hp.top() == max);
        CHECK_FALSE(hp.empty());
      }
    }
  });
}

void test_heap_permutations_delete(std::vector<text_item> items){
  permute(items, [](text_item const& a, text_item const& b){
    return a.freq > b.freq;
  }, [](std::vector<text_item> const& items, std::vector<text_item> const& sorted_items){
    SECTION(to_string(items)){
      max_heap hp(items.size());
      CHECK_THROWS_AS(hp.top(), std::logic_error);
      CHECK_THROWS_AS(hp.delete_max(), std::logic_error);
      text_item max{"aaaa", std::numeric_limits<int>::lowest()};
      for(auto const& item: items){
        hp.insert(item);
      }
      for(auto const& item: sorted_items){
        CHECK(item == hp.top());
        CHECK(item == hp.delete_max());
      }
      CHECK(hp.empty());
    }
  });
}

TEST_CASE("max_heap_insert", "[max_heap]"){
  SECTION("empty"){
    test_heap_permutations_insert({});
  }
  SECTION("too many"){
    max_heap hp(1);
    hp.insert(text_item{"a", 1});
    CHECK_THROWS_AS(hp.insert(text_item{"a", 2}), std::logic_error);
  }
  SECTION("one element"){
    test_heap_permutations_insert({text_item{"aaaa", 1}});
  }
  SECTION("5 elements"){
    test_heap_permutations_insert({
      text_item{"aaaa", 1},
      text_item{"bbbb", 2},
      text_item{"cccc", 3},
      text_item{"dddd", 4},
      text_item{"eeee", 5}
    });
  }
}

TEST_CASE("max_heap_delete", "[max_heap]"){
  SECTION("empty"){
    test_heap_permutations_delete({});
  }
  SECTION("one element"){
    test_heap_permutations_delete({text_item{"aaaa", 1}});
  }
  SECTION("5 elements"){
    test_heap_permutations_delete({
      text_item{"aaaa", 1},
      text_item{"bbbb", 2},
      text_item{"cccc", 3},
      text_item{"dddd", 4},
      text_item{"eeee", 5}
    });
  }
}

TEST_CASE("max_heap_swap_up", "[max_heap]"){
  SECTION("only"){
    max_heap hp(1);
    hp.insert(text_item{"aaaa", 1});
    CHECK(hp.top() == (text_item{"aaaa", 1}));
  }
  SECTION("left"){
    max_heap hp(4);
    hp.insert(text_item{"aaaa", 3});
    hp.insert(text_item{"aaaa", 2});
    hp.insert(text_item{"aaaa", 1});
    hp.insert(text_item{"aaaa", 4});
    CHECK(hp.top() == (text_item{"aaaa", 4}));
  }
  SECTION("right"){
    max_heap hp(5);
    hp.insert(text_item{"aaaa", 4});
    hp.insert(text_item{"aaaa", 3});
    hp.insert(text_item{"aaaa", 2});
    hp.insert(text_item{"aaaa", 1});
    hp.insert(text_item{"aaaa", 5});
    CHECK(hp.top() == (text_item{"aaaa", 5}));
  }
}

TEST_CASE("max_heap_swap_down", "[max_heap]"){
  SECTION("only"){
    max_heap hp(1);
    hp.insert(text_item{"aaaa", 1});
    CHECK(hp.delete_max() == (text_item{"aaaa", 1}));
  }
  SECTION("left"){
    max_heap hp(5);
    hp.insert(text_item{"aaaa", 5});
    hp.insert(text_item{"aaaa", 4});
    hp.insert(text_item{"aaaa", 3});
    hp.insert(text_item{"aaaa", 2});
    hp.insert(text_item{"aaaa", 1});

    CHECK(hp.delete_max() == (text_item{"aaaa", 5}));
    CHECK(hp.top() == (text_item{"aaaa", 4}));
  }
  SECTION("right"){
    max_heap hp(6);
    hp.insert(text_item{"aaaa", 6});
    hp.insert(text_item{"aaaa", 5});
    hp.insert(text_item{"aaaa", 4});
    hp.insert(text_item{"aaaa", 3});
    hp.insert(text_item{"aaaa", 2});
    hp.insert(text_item{"aaaa", 1});
    CHECK(hp.delete_max() == (text_item{"aaaa", 6}));
    CHECK(hp.top() == (text_item{"aaaa", 5}));
  }
}

TEST_CASE("test_bst_many", "[string_bst]"){
  permute(std::vector<std::string>{"aa", "ab", "cb", "ab", "cb"}, [](std::string const& a, std::string const& b){
    return a < b;
  }, [](std::vector<std::string> const& items, std::vector<std::string> const& sorted_items){
    SECTION(to_string(items)){
      string_bst t;
      for(auto const& item: sorted_items){
        CHECK(t.word_frequency(item) == 0);
      }
      for(auto const& item: items){
        t.insert(item);
      }
      CHECK(t.size() == 3);
      CHECK(t.word_frequency("aa") == 1);
      CHECK(t.word_frequency("ab") == 2);
      CHECK(t.word_frequency("ba") == 0);
      CHECK(t.word_frequency("ca") == 0);
      CHECK(t.word_frequency("cb") == 2);
      CHECK(t.word_frequency("ac") == 0);
    }
  });
}
