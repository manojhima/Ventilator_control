file(REMOVE_RECURSE
  "cycles_test.pdb"
  "cycles_test"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/cycles_test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
