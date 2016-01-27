#ifndef cfg_H
#define cfg_H

typedef double Dtype;

struct cfg
{
    static int dev_id, iter; 
    static unsigned bptt, n_recur_layers;     
    static unsigned n_hidden; 
    static unsigned n_embed; 
    static unsigned batch_size; 
    static unsigned max_epoch; 
    static unsigned test_interval; 
    static unsigned report_interval; 
    static unsigned save_interval; 
    static Dtype lr;
    static Dtype l2_penalty; 
    static Dtype momentum; 
    static MatMode device_type;
    static const char *f_time_data, *f_event_data, *save_dir;
    
    static void LoadParams(const int argc, const char** argv)
    {
        for (int i = 1; i < argc; i += 2)
        {
            if (strcmp(argv[i], "-time") == 0)
                f_time_data = argv[i + 1];
            if (strcmp(argv[i], "-mode") == 0)
		    {
		        if (strcmp(argv[i + 1], "CPU") == 0)
		            device_type = CPU;
		        else if (strcmp(argv[i + 1], "GPU") == 0)
		            device_type = GPU;
		        else throw "unknown device"; 
                std::cerr << "device_type = " << argv[i + 1] << std::endl;
		    }
		    if (strcmp(argv[i], "-event") == 0)
		        f_event_data = argv[i + 1];                
		    if (strcmp(argv[i], "-lr") == 0)
		        lr = atof(argv[i + 1]);
            if (strcmp(argv[i], "-bptt") == 0)
                bptt = atoi(argv[i + 1]);                                    
            if (strcmp(argv[i], "-cur_iter") == 0)
                iter = atoi(argv[i + 1]);
		    if (strcmp(argv[i], "-hidden") == 0)
			    n_hidden = atoi(argv[i + 1]);
		    if (strcmp(argv[i], "-embed") == 0)
			    n_embed = atoi(argv[i + 1]);                    
		    if (strcmp(argv[i], "-b") == 0)
    			batch_size = atoi(argv[i + 1]);
    		if (strcmp(argv[i], "-maxe") == 0)
	       		max_epoch = atoi(argv[i + 1]);
		    if (strcmp(argv[i], "-int_test") == 0)
    			test_interval = atoi(argv[i + 1]);
    	   	if (strcmp(argv[i], "-int_report") == 0)
    			report_interval = atoi(argv[i + 1]);
    		if (strcmp(argv[i], "-int_save") == 0)
    			save_interval = atoi(argv[i + 1]);
    		if (strcmp(argv[i], "-l2") == 0)
    			l2_penalty = atof(argv[i + 1]);
    		if (strcmp(argv[i], "-m") == 0)
    			momentum = atof(argv[i + 1]);	
    		if (strcmp(argv[i], "-svdir") == 0)
    			save_dir = argv[i + 1];
            if (strcmp(argv[i], "-device") == 0)
    			dev_id = atoi(argv[i + 1]);
        }
	
        std::cerr << "bptt = " << bptt << std::endl;
	    std::cerr << "n_hidden = " << n_hidden << std::endl;
        std::cerr << "n_embed = " << n_embed << std::endl;
        std::cerr << "batch_size = " << batch_size << std::endl;
        std::cerr << "max_epoch = " << max_epoch << std::endl;
    	std::cerr << "test_interval = " << test_interval << std::endl;
    	std::cerr << "report_interval = " << report_interval << std::endl;
    	std::cerr << "save_interval = " << save_interval << std::endl;
    	std::cerr << "lr = " << lr << std::endl;
    	std::cerr << "l2_penalty = " << l2_penalty << std::endl;
    	std::cerr << "momentum = " << momentum << std::endl;
    	std::cerr << "init iter = " << iter << std::endl;	
        std::cerr << "device id = " << dev_id << std::endl;    
    }    
};

int cfg::dev_id = 0;
int cfg::iter = 0;
unsigned cfg::bptt = 3;
unsigned cfg::n_recur_layers = 1;

unsigned cfg::n_hidden = 256;
unsigned cfg::n_embed = 128;
unsigned cfg::batch_size = 50;
unsigned cfg::max_epoch = 200;
unsigned cfg::test_interval = 10000;
unsigned cfg::report_interval = 100;
unsigned cfg::save_interval = 50000;
Dtype cfg::lr = 0.0005;
Dtype cfg::l2_penalty = 0;
Dtype cfg::momentum = 0;
MatMode cfg::device_type = GPU;
const char* cfg::f_time_data = nullptr;
const char* cfg::f_event_data = nullptr;
const char* cfg::save_dir = "./saved";


#endif