// Generated by rstantools.  Do not edit by hand.

/*
    SignIT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SignIT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SignIT.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1
#include <stan/model/model_header.hpp>
namespace model_signature_model_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_signature_model");
    reader.add_event(31, 29, "end", "model_signature_model");
    return reader;
}
#include <stan_meta_header.hpp>
class model_signature_model : public prob_grad {
private:
        int S;
        int N;
        int R;
        std::vector<int> v;
        matrix_d ref_signatures;
public:
    model_signature_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_signature_model(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_signature_model_namespace::model_signature_model";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "S", "int", context__.to_vec());
            S = int(0);
            vals_i__ = context__.vals_i("S");
            pos__ = 0;
            S = vals_i__[pos__++];
            check_greater_or_equal(function__, "S", S, 1);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "R", "int", context__.to_vec());
            R = int(0);
            vals_i__ = context__.vals_i("R");
            pos__ = 0;
            R = vals_i__[pos__++];
            check_greater_or_equal(function__, "R", R, 1);
            current_statement_begin__ = 5;
            validate_non_negative_index("v", "R", R);
            context__.validate_dims("data initialization", "v", "int", context__.to_vec(R));
            v = std::vector<int>(R, int(0));
            vals_i__ = context__.vals_i("v");
            pos__ = 0;
            size_t v_k_0_max__ = R;
            for (size_t k_0__ = 0; k_0__ < v_k_0_max__; ++k_0__) {
                v[k_0__] = vals_i__[pos__++];
            }
            size_t v_i_0_max__ = R;
            for (size_t i_0__ = 0; i_0__ < v_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "v[i_0__]", v[i_0__], 0);
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("ref_signatures", "R", R);
            validate_non_negative_index("ref_signatures", "S", S);
            context__.validate_dims("data initialization", "ref_signatures", "matrix_d", context__.to_vec(R,S));
            ref_signatures = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(R, S);
            vals_r__ = context__.vals_r("ref_signatures");
            pos__ = 0;
            size_t ref_signatures_j_2_max__ = S;
            size_t ref_signatures_j_1_max__ = R;
            for (size_t j_2__ = 0; j_2__ < ref_signatures_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < ref_signatures_j_1_max__; ++j_1__) {
                    ref_signatures(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 10;
            validate_non_negative_index("exposures", "S", S);
            num_params_r__ += (S - 1);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_signature_model() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 10;
        if (!(context__.contains_r("exposures")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable exposures missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("exposures");
        pos__ = 0U;
        validate_non_negative_index("exposures", "S", S);
        context__.validate_dims("parameter initialization", "exposures", "vector_d", context__.to_vec(S));
        Eigen::Matrix<double, Eigen::Dynamic, 1> exposures(S);
        size_t exposures_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
            exposures(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.simplex_unconstrain(exposures);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable exposures: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 10;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> exposures;
            (void) exposures;  // dummy to suppress unused var warning
            if (jacobian__)
                exposures = in__.simplex_constrain(S, lp__);
            else
                exposures = in__.simplex_constrain(S);
            // transformed parameters
            current_statement_begin__ = 14;
            validate_non_negative_index("sim_catalog", "R", R);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> sim_catalog(R);
            stan::math::initialize(sim_catalog, DUMMY_VAR__);
            stan::math::fill(sim_catalog, DUMMY_VAR__);
            current_statement_begin__ = 15;
            validate_non_negative_index("sim_catalog_prob", "R", R);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> sim_catalog_prob(R);
            stan::math::initialize(sim_catalog_prob, DUMMY_VAR__);
            stan::math::fill(sim_catalog_prob, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 16;
            stan::math::assign(sim_catalog, multiply(multiply(ref_signatures, exposures), N));
            current_statement_begin__ = 17;
            stan::math::assign(sim_catalog_prob, divide(sim_catalog, sum(sim_catalog)));
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 14;
            size_t sim_catalog_j_1_max__ = R;
            for (size_t j_1__ = 0; j_1__ < sim_catalog_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(sim_catalog(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: sim_catalog" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable sim_catalog: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 15;
            size_t sim_catalog_prob_j_1_max__ = R;
            for (size_t j_1__ = 0; j_1__ < sim_catalog_prob_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(sim_catalog_prob(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: sim_catalog_prob" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable sim_catalog_prob: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            stan::math::check_simplex(function__, "sim_catalog_prob", sim_catalog_prob);
            // model body
            current_statement_begin__ = 21;
            lp_accum__.add(dirichlet_log<propto__>(exposures, rep_vector(1, S)));
            current_statement_begin__ = 22;
            lp_accum__.add(multinomial_log<propto__>(v, sim_catalog_prob));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("exposures");
        names__.push_back("sim_catalog");
        names__.push_back("sim_catalog_prob");
        names__.push_back("log_lik");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(S);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(R);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(R);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_signature_model_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> exposures = in__.simplex_constrain(S);
        size_t exposures_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
            vars__.push_back(exposures(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 14;
            validate_non_negative_index("sim_catalog", "R", R);
            Eigen::Matrix<double, Eigen::Dynamic, 1> sim_catalog(R);
            stan::math::initialize(sim_catalog, DUMMY_VAR__);
            stan::math::fill(sim_catalog, DUMMY_VAR__);
            current_statement_begin__ = 15;
            validate_non_negative_index("sim_catalog_prob", "R", R);
            Eigen::Matrix<double, Eigen::Dynamic, 1> sim_catalog_prob(R);
            stan::math::initialize(sim_catalog_prob, DUMMY_VAR__);
            stan::math::fill(sim_catalog_prob, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 16;
            stan::math::assign(sim_catalog, multiply(multiply(ref_signatures, exposures), N));
            current_statement_begin__ = 17;
            stan::math::assign(sim_catalog_prob, divide(sim_catalog, sum(sim_catalog)));
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 15;
            stan::math::check_simplex(function__, "sim_catalog_prob", sim_catalog_prob);
            // write transformed parameters
            if (include_tparams__) {
                size_t sim_catalog_j_1_max__ = R;
                for (size_t j_1__ = 0; j_1__ < sim_catalog_j_1_max__; ++j_1__) {
                    vars__.push_back(sim_catalog(j_1__));
                }
                size_t sim_catalog_prob_j_1_max__ = R;
                for (size_t j_1__ = 0; j_1__ < sim_catalog_prob_j_1_max__; ++j_1__) {
                    vars__.push_back(sim_catalog_prob(j_1__));
                }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 26;
            double log_lik;
            (void) log_lik;  // dummy to suppress unused var warning
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // generated quantities statements
            current_statement_begin__ = 28;
            stan::math::assign(log_lik, multinomial_log(v, sim_catalog_prob));
            // validate, write generated quantities
            current_statement_begin__ = 26;
            vars__.push_back(log_lik);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    static std::string model_name() {
        return "model_signature_model";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t exposures_j_1_max__ = S;
        for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "exposures" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t sim_catalog_j_1_max__ = R;
            for (size_t j_1__ = 0; j_1__ < sim_catalog_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sim_catalog" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t sim_catalog_prob_j_1_max__ = R;
            for (size_t j_1__ = 0; j_1__ < sim_catalog_prob_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sim_catalog_prob" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "log_lik";
        param_names__.push_back(param_name_stream__.str());
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t exposures_j_1_max__ = (S - 1);
        for (size_t j_1__ = 0; j_1__ < exposures_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "exposures" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t sim_catalog_j_1_max__ = R;
            for (size_t j_1__ = 0; j_1__ < sim_catalog_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sim_catalog" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t sim_catalog_prob_j_1_max__ = (R - 1);
            for (size_t j_1__ = 0; j_1__ < sim_catalog_prob_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sim_catalog_prob" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "log_lik";
        param_names__.push_back(param_name_stream__.str());
    }
}; // model
}  // namespace
typedef model_signature_model_namespace::model_signature_model stan_model;
#endif
