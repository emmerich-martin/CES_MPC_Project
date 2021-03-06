#include "MTSOS.h"

int main(){
    problem_params p_params;
    algorithm_flags a_flags;
    algorithm_params a_params;
    optional_params o_params;
    double* b, *u, *v, *timers;
    double fx;
    int iterations, i;
    double total_time = 0;
    double vars[2] = {1, 1};
    double S[402] = { 0.9501,
0.2311,
0.9154,
0.2201,
0.8825,
0.2105,
0.8513,
0.2021,
0.8219,
0.1949,
0.7941,
0.1890,
0.7680,
0.1842,
0.7436,
0.1806,
0.7207,
0.1781,
0.6993,
0.1767,
0.6795,
0.1763,
0.6611,
0.1769,
0.6441,
0.1785,
0.6286,
0.1811,
0.6144,
0.1846,
0.6016,
0.1889,
0.5900,
0.1941,
0.5797,
0.2001,
0.5707,
0.2069,
0.5628,
0.2144,
0.5560,
0.2227,
0.5504,
0.2316,
0.5458,
0.2412,
0.5423,
0.2514,
0.5398,
0.2621,
0.5383,
0.2734,
0.5377,
0.2853,
0.5379,
0.2976,
0.5391,
0.3103,
0.5411,
0.3235,
0.5438,
0.3370,
0.5473,
0.3509,
0.5516,
0.3651,
0.5565,
0.3796,
0.5620,
0.3943,
0.5682,
0.4092,
0.5749,
0.4244,
0.5822,
0.4396,
0.5899,
0.4550,
0.5982,
0.4705,
0.6068,
0.4860,
0.6159,
0.5015,
0.6253,
0.5170,
0.6350,
0.5324,
0.6451,
0.5478,
0.6553,
0.5630,
0.6658,
0.5781,
0.6764,
0.5930,
0.6872,
0.6077,
0.6981,
0.6221,
0.7091,
0.6363,
0.7201,
0.6501,
0.7311,
0.6636,
0.7421,
0.6767,
0.7529,
0.6893,
0.7637,
0.7015,
0.7743,
0.7132,
0.7848,
0.7245,
0.7950,
0.7351,
0.8049,
0.7452,
0.8146,
0.7546,
0.8239,
0.7634,
0.8329,
0.7715,
0.8415,
0.7789,
0.8496,
0.7855,
0.8573,
0.7914,
0.8645,
0.7964,
0.8711,
0.8006,
0.8771,
0.8039,
0.8826,
0.8062,
0.8873,
0.8076,
0.8914,
0.8081,
0.8948,
0.8075,
0.8974,
0.8059,
0.8992,
0.8031,
0.9002,
0.7993,
0.9003,
0.7943,
0.8995,
0.7881,
0.8977,
0.7807,
0.8950,
0.7720,
0.8913,
0.7621,
0.8865,
0.7509,
0.8808,
0.7384,
0.8741,
0.7247,
0.8665,
0.7099,
0.8581,
0.6941,
0.8489,
0.6773,
0.8390,
0.6596,
0.8284,
0.6410,
0.8172,
0.6217,
0.8055,
0.6017,
0.7932,
0.5810,
0.7804,
0.5598,
0.7673,
0.5382,
0.7538,
0.5160,
0.7400,
0.4936,
0.7260,
0.4708,
0.7118,
0.4478,
0.6974,
0.4247,
0.6830,
0.4015,
0.6686,
0.3783,
0.6541,
0.3552,
0.6398,
0.3322,
0.6256,
0.3093,
0.6115,
0.2868,
0.5978,
0.2646,
0.5843,
0.2428,
0.5711,
0.2214,
0.5584,
0.2006,
0.5461,
0.1804,
0.5343,
0.1609,
0.5231,
0.1422,
0.5125,
0.1243,
0.5026,
0.1072,
0.4934,
0.0911,
0.4850,
0.0760,
0.4774,
0.0621,
0.4707,
0.0493,
0.4650,
0.0377,
0.4602,
0.0274,
0.4565,
0.0185,
0.4538,
0.0110,
0.4523,
0.0049,
0.4517,
0.0002,
0.4522,
-0.0032,
0.4536,
-0.0053,
0.4559,
-0.0061,
0.4591,
-0.0058,
0.4632,
-0.0042,
0.4680,
-0.0015,
0.4737,
0.0022,
0.4800,
0.0071,
0.4871,
0.0130,
0.4949,
0.0199,
0.5032,
0.0277,
0.5122,
0.0364,
0.5217,
0.0461,
0.5317,
0.0566,
0.5422,
0.0678,
0.5532,
0.0799,
0.5645,
0.0927,
0.5763,
0.1061,
0.5883,
0.1203,
0.6007,
0.1350,
0.6133,
0.1504,
0.6262,
0.1662,
0.6392,
0.1826,
0.6524,
0.1995,
0.6657,
0.2168,
0.6791,
0.2345,
0.6926,
0.2525,
0.7060,
0.2709,
0.7195,
0.2896,
0.7328,
0.3085,
0.7461,
0.3276,
0.7592,
0.3469,
0.7721,
0.3664,
0.7848,
0.3859,
0.7973,
0.4055,
0.8095,
0.4251,
0.8214,
0.4447,
0.8329,
0.4643,
0.8441,
0.4837,
0.8548,
0.5031,
0.8650,
0.5223,
0.8747,
0.5413,
0.8839,
0.5600,
0.8925,
0.5785,
0.9005,
0.5967,
0.9079,
0.6145,
0.9145,
0.6319,
0.9205,
0.6489,
0.9257,
0.6655,
0.9301,
0.6816,
0.9336,
0.6971,
0.9363,
0.7121,
0.9381,
0.7264,
0.9390,
0.7401,
0.9389,
0.7531,
0.9377,
0.7655,
0.9356,
0.7770,
0.9323,
0.7878,
0.9279,
0.7977,
0.9223,
0.8067,
0.9156,
0.8149,
0.9076,
0.8221,
0.8984,
0.8283,
0.8878,
0.8336,
0.8759,
0.8377,
0.8627,
0.8408,
0.8480,
0.8427,
0.8319,
0.8435,
0.8143,
0.8431,
0.7951,
0.8414,
0.7744,
0.8385,
0.7521,
0.8342,
0.7282,
0.8286,
0.7026,
0.8216,
0.6753,
0.8132,
0.6463,
0.8033,
0.6154,
0.7919};
        b = NULL;
        v = NULL;
        u = NULL;
        timers = NULL;
        fx = 0;
        iterations = 0;
        p_params.S = S;
        p_params.S_length = 201;
        p_params.initial_velocity = 0;
        p_params.State_size = 2;
        p_params.U_size = 2;
        a_flags.timer = 1;
        a_flags.display = 0;
        a_flags.kappa = 1;
        a_params.kappa = 0;
        a_params.alpha = 0;
        a_params.beta = 0;
        a_params.epsilon = .01;
        a_params.MAX_ITER = 0;
        o_params.variables = vars;
        o_params.variables_length = 2;
        o_params.initial_b = 0;
        o_params.initial_u = 0;
	printf("Running test for MTSOS.\n");
        so_MTSOS(&p_params, &a_flags, &a_params, &o_params, &b, &u, &v, &fx, &timers, &iterations);
        printf("the optimal time to traverse is %6.4f.\n", fx);
        
	if(abs(fx-8.3287)<1e-3){
	  for(i = 0; i < 9; i++){
            total_time += timers[i];
	  }
	  printf("the time to compute is %f milliseconds.\n",total_time);
	  printf("MTSOS is working!\n");
	}
	else
	  printf("The optimal time to traverse should have been 8.3287. \n There appears to be a problem with your BLAS linking.\n  See http://www.stanford.edu/~boyd/MTSOS/install.html for more information.\n");
        

	if(b != NULL){
            free(b);
        }
        if(u != NULL){
            free(u);
        }
        if(v != NULL){
            free(v);
        }
        if(timers != NULL){
            free(timers);
        }
        return 0;
}
