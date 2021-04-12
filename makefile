
main_c_file := main_selection_sort.c
auxillary_c_sources := gen_rand_array.c
main_prog_file = $(basename $(main_c_file))

all: $(main_c_file) $(auxillary_c_sources)
	gcc -g -o $(main_prog_file) $? $(CPPFLAGS) -lOpenCL $(LDFLAGS)

clean:
	rm -f $(main_prog_file)

