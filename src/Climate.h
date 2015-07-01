#ifndef _CLIMATE_H_
#define _CLIMATE_H_

#include <string>
#include <vector>

class Climate {
public:

  Climate();
  Climate(const std::string& fname, int y, int x);

  // driving variables
  std::vector<float> tair;
  std::vector<float> prec;
  std::vector<float> nirr;
  std::vector<float> vapo;

  // calculated driving variables
  std::vector<float> rain;
  std::vector<float> snow;
  std::vector<float> girr;
  std::vector<float> cld;
  std::vector<float> par;

  // simplified climate, averaged over some number of years
  std::vector<float> avgX_tair;
  std::vector<float> avgX_prec;
  std::vector<float> avgX_nirr;
  std::vector<float> avgX_vapo;

  std::vector<float> tair_d;
  std::vector<float> prec_d;
  std::vector<float> nirr_d;
  std::vector<float> vapo_d;
  std::vector<float> rain_d;
  std::vector<float> snow_d;
  std::vector<float> girr_d;
  std::vector<float> cld_d;
  std::vector<float> par_d;

  std::vector<float> rhoa_d;
  std::vector<float> svp_d;
  std::vector<float> vpd_d;
  std::vector<float> dersvp_d;
  std::vector<float> abshd_d;
  

private:

  void load_from_file(const std::string& fname, int y, int x);

  void split_precip();

  std::vector<float> avg_over(const std::vector<float> & var, const int window);

  std::vector<float> interpolate_daily(const std::vector<float> & var);

};

#endif /* _CLIMATE_H_ */


