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
namespace model_signit_model_infer_populations_namespace {
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
    reader.add_event(0, 0, "start", "model_signit_model_infer_populations");
    reader.add_event(93, 91, "end", "model_signit_model_infer_populations");
    return reader;
}
template <typename T5__, typename T6__, typename T7__, typename T9__, typename T10__>
typename boost::math::tools::promote_args<T5__, T6__, T7__, T9__, typename boost::math::tools::promote_args<T10__>::type>::type
compute_log_likelihood(const int& N,
                           const int& L,
                           const int& K,
                           const std::vector<int>& x,
                           const std::vector<int>& d,
                           const Eigen::Matrix<T5__, Eigen::Dynamic, 1>& a,
                           const Eigen::Matrix<T6__, Eigen::Dynamic, 1>& mu,
                           const T7__& kappa_minus_two,
                           const std::vector<int>& v,
                           const Eigen::Matrix<T9__, Eigen::Dynamic, Eigen::Dynamic>& ref_signatures,
                           const Eigen::Matrix<T10__, Eigen::Dynamic, 1>& phi, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T5__, T6__, T7__, T9__, typename boost::math::tools::promote_args<T10__>::type>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 5;
        validate_non_negative_index("alpha", "N", N);
        validate_non_negative_index("alpha", "L", L);
        std::vector<std::vector<local_scalar_t__  >  > alpha(N, std::vector<local_scalar_t__>(L, local_scalar_t__(DUMMY_VAR__)));
        stan::math::initialize(alpha, DUMMY_VAR__);
        stan::math::fill(alpha, DUMMY_VAR__);
        current_statement_begin__ = 6;
        validate_non_negative_index("beta", "N", N);
        validate_non_negative_index("beta", "L", L);
        std::vector<std::vector<local_scalar_t__  >  > beta(N, std::vector<local_scalar_t__>(L, local_scalar_t__(DUMMY_VAR__)));
        stan::math::initialize(beta, DUMMY_VAR__);
        stan::math::fill(beta, DUMMY_VAR__);
        current_statement_begin__ = 9;
        validate_non_negative_index("sig_likelihood", "N", N);
        validate_non_negative_index("sig_likelihood", "K", K);
        std::vector<std::vector<local_scalar_t__  >  > sig_likelihood(N, std::vector<local_scalar_t__>(K, local_scalar_t__(DUMMY_VAR__)));
        stan::math::initialize(sig_likelihood, DUMMY_VAR__);
        stan::math::fill(sig_likelihood, DUMMY_VAR__);
        current_statement_begin__ = 10;
        validate_non_negative_index("pop_likelihood", "N", N);
        validate_non_negative_index("pop_likelihood", "L", L);
        std::vector<std::vector<local_scalar_t__  >  > pop_likelihood(N, std::vector<local_scalar_t__>(L, local_scalar_t__(DUMMY_VAR__)));
        stan::math::initialize(pop_likelihood, DUMMY_VAR__);
        stan::math::fill(pop_likelihood, DUMMY_VAR__);
        current_statement_begin__ = 11;
        validate_non_negative_index("likelihood_sums", "L", L);
        validate_non_negative_index("likelihood_sums", "K", K);
        validate_non_negative_index("likelihood_sums", "N", N);
        std::vector<std::vector<std::vector<local_scalar_t__  >  >  > likelihood_sums(L, std::vector<std::vector<local_scalar_t__> >(K, std::vector<local_scalar_t__>(N, local_scalar_t__(DUMMY_VAR__))));
        stan::math::initialize(likelihood_sums, DUMMY_VAR__);
        stan::math::fill(likelihood_sums, DUMMY_VAR__);
        current_statement_begin__ = 12;
        int idx(0);
        (void) idx;  // dummy to suppress unused var warning
        stan::math::fill(idx, std::numeric_limits<int>::min());
        current_statement_begin__ = 13;
        local_scalar_t__ log_likelihood(DUMMY_VAR__);
        (void) log_likelihood;  // dummy to suppress unused var warning
        stan::math::initialize(log_likelihood, DUMMY_VAR__);
        stan::math::fill(log_likelihood, DUMMY_VAR__);
        current_statement_begin__ = 15;
        stan::math::assign(alpha, to_array_2d(multiply(multiply(a, to_row_vector(mu)), (kappa_minus_two + 2))));
        current_statement_begin__ = 16;
        stan::math::assign(beta, to_array_2d(multiply(subtract(1, multiply(a, to_row_vector(mu))), (kappa_minus_two + 2))));
        current_statement_begin__ = 18;
        for (int n = 1; n <= N; ++n) {
            current_statement_begin__ = 19;
            for (int l = 1; l <= L; ++l) {
                current_statement_begin__ = 20;
                stan::model::assign(pop_likelihood, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_uni(l), stan::model::nil_index_list())), 
                            beta_binomial_log(get_base1(x, n, "x", 1), get_base1(d, n, "d", 1), get_base1(get_base1(alpha, n, "alpha", 1), l, "alpha", 2), get_base1(get_base1(beta, n, "beta", 1), l, "beta", 2)), 
                            "assigning variable pop_likelihood");
            }
        }
        current_statement_begin__ = 24;
        for (int n = 1; n <= N; ++n) {
            current_statement_begin__ = 25;
            for (int k = 1; k <= K; ++k) {
                current_statement_begin__ = 26;
                stan::model::assign(sig_likelihood, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), 
                            categorical_log(get_base1(v, n, "v", 1), to_vector(get_base1(ref_signatures, k, "ref_signatures", 1))), 
                            "assigning variable sig_likelihood");
            }
        }
        current_statement_begin__ = 30;
        for (int l = 1; l <= L; ++l) {
            current_statement_begin__ = 31;
            for (int k = 1; k <= K; ++k) {
                current_statement_begin__ = 32;
                stan::math::assign(idx, (((l - 1) * K) + k));
                current_statement_begin__ = 33;
                stan::model::assign(likelihood_sums, 
                            stan::model::cons_list(stan::model::index_uni(l), stan::model::cons_list(stan::model::index_uni(k), stan::model::cons_list(stan::model::index_omni(), stan::model::nil_index_list()))), 
                            to_array_1d(add(add(stan::math::log(get_base1(phi, idx, "phi", 1)), to_vector(stan::model::rvalue(pop_likelihood, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(l), stan::model::nil_index_list())), "pop_likelihood"))), to_vector(stan::model::rvalue(sig_likelihood, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), "sig_likelihood")))), 
                            "assigning variable likelihood_sums");
            }
        }
        current_statement_begin__ = 37;
        stan::math::assign(likelihood_sums, stan::math::exp(likelihood_sums));
        current_statement_begin__ = 39;
        stan::math::assign(log_likelihood, 0);
        current_statement_begin__ = 40;
        for (int n = 1; n <= N; ++n) {
            current_statement_begin__ = 41;
            stan::math::assign(log_likelihood, (log_likelihood + stan::math::log(sum(to_array_1d(stan::model::rvalue(likelihood_sums, stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()))), "likelihood_sums"))))));
        }
        current_statement_begin__ = 44;
        return stan::math::promote_scalar<fun_return_scalar_t__>(log_likelihood);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
struct compute_log_likelihood_functor__ {
    template <typename T5__, typename T6__, typename T7__, typename T9__, typename T10__>
        typename boost::math::tools::promote_args<T5__, T6__, T7__, T9__, typename boost::math::tools::promote_args<T10__>::type>::type
    operator()(const int& N,
                           const int& L,
                           const int& K,
                           const std::vector<int>& x,
                           const std::vector<int>& d,
                           const Eigen::Matrix<T5__, Eigen::Dynamic, 1>& a,
                           const Eigen::Matrix<T6__, Eigen::Dynamic, 1>& mu,
                           const T7__& kappa_minus_two,
                           const std::vector<int>& v,
                           const Eigen::Matrix<T9__, Eigen::Dynamic, Eigen::Dynamic>& ref_signatures,
                           const Eigen::Matrix<T10__, Eigen::Dynamic, 1>& phi, std::ostream* pstream__) const {
        return compute_log_likelihood(N, L, K, x, d, a, mu, kappa_minus_two, v, ref_signatures, phi, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_signit_model_infer_populations : public prob_grad {
private:
        int N;
        int K;
        int R;
        std::vector<int> v;
        matrix_d ref_signatures;
        int L;
        std::vector<int> x;
        std::vector<int> d;
        vector_d a;
public:
    model_signit_model_infer_populations(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_signit_model_infer_populations(stan::io::var_context& context__,
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
        static const char* function__ = "model_signit_model_infer_populations_namespace::model_signit_model_infer_populations";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 49;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 52;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 1);
            current_statement_begin__ = 53;
            context__.validate_dims("data initialization", "R", "int", context__.to_vec());
            R = int(0);
            vals_i__ = context__.vals_i("R");
            pos__ = 0;
            R = vals_i__[pos__++];
            check_greater_or_equal(function__, "R", R, 1);
            current_statement_begin__ = 54;
            validate_non_negative_index("v", "N", N);
            context__.validate_dims("data initialization", "v", "int", context__.to_vec(N));
            v = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("v");
            pos__ = 0;
            size_t v_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < v_k_0_max__; ++k_0__) {
                v[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 55;
            validate_non_negative_index("ref_signatures", "K", K);
            validate_non_negative_index("ref_signatures", "R", R);
            context__.validate_dims("data initialization", "ref_signatures", "matrix_d", context__.to_vec(K,R));
            ref_signatures = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(K, R);
            vals_r__ = context__.vals_r("ref_signatures");
            pos__ = 0;
            size_t ref_signatures_j_2_max__ = R;
            size_t ref_signatures_j_1_max__ = K;
            for (size_t j_2__ = 0; j_2__ < ref_signatures_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < ref_signatures_j_1_max__; ++j_1__) {
                    ref_signatures(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 58;
            context__.validate_dims("data initialization", "L", "int", context__.to_vec());
            L = int(0);
            vals_i__ = context__.vals_i("L");
            pos__ = 0;
            L = vals_i__[pos__++];
            check_greater_or_equal(function__, "L", L, 1);
            current_statement_begin__ = 59;
            validate_non_negative_index("x", "N", N);
            context__.validate_dims("data initialization", "x", "int", context__.to_vec(N));
            x = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("x");
            pos__ = 0;
            size_t x_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < x_k_0_max__; ++k_0__) {
                x[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 60;
            validate_non_negative_index("d", "N", N);
            context__.validate_dims("data initialization", "d", "int", context__.to_vec(N));
            d = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("d");
            pos__ = 0;
            size_t d_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < d_k_0_max__; ++k_0__) {
                d[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 61;
            validate_non_negative_index("a", "N", N);
            context__.validate_dims("data initialization", "a", "vector_d", context__.to_vec(N));
            a = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
            vals_r__ = context__.vals_r("a");
            pos__ = 0;
            size_t a_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                a(j_1__) = vals_r__[pos__++];
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 65;
            validate_non_negative_index("phi", "(L * K)", (L * K));
            num_params_r__ += ((L * K) - 1);
            current_statement_begin__ = 67;
            validate_non_negative_index("mu_ordered", "L", L);
            num_params_r__ += L;
            current_statement_begin__ = 68;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_signit_model_infer_populations() { }
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
        current_statement_begin__ = 65;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        validate_non_negative_index("phi", "(L * K)", (L * K));
        context__.validate_dims("parameter initialization", "phi", "vector_d", context__.to_vec((L * K)));
        Eigen::Matrix<double, Eigen::Dynamic, 1> phi((L * K));
        size_t phi_j_1_max__ = (L * K);
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            phi(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.simplex_unconstrain(phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 67;
        if (!(context__.contains_r("mu_ordered")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu_ordered missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu_ordered");
        pos__ = 0U;
        validate_non_negative_index("mu_ordered", "L", L);
        context__.validate_dims("parameter initialization", "mu_ordered", "vector_d", context__.to_vec(L));
        Eigen::Matrix<double, Eigen::Dynamic, 1> mu_ordered(L);
        size_t mu_ordered_j_1_max__ = L;
        for (size_t j_1__ = 0; j_1__ < mu_ordered_j_1_max__; ++j_1__) {
            mu_ordered(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.ordered_unconstrain(mu_ordered);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu_ordered: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 68;
        if (!(context__.contains_r("kappa_minus_two")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable kappa_minus_two missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("kappa_minus_two");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "kappa_minus_two", "double", context__.to_vec());
        double kappa_minus_two(0);
        kappa_minus_two = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, kappa_minus_two);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable kappa_minus_two: ") + e.what()), current_statement_begin__, prog_reader__());
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
            current_statement_begin__ = 65;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.simplex_constrain((L * K), lp__);
            else
                phi = in__.simplex_constrain((L * K));
            current_statement_begin__ = 67;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> mu_ordered;
            (void) mu_ordered;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_ordered = in__.ordered_constrain(L, lp__);
            else
                mu_ordered = in__.ordered_constrain(L);
            current_statement_begin__ = 68;
            local_scalar_t__ kappa_minus_two;
            (void) kappa_minus_two;  // dummy to suppress unused var warning
            if (jacobian__)
                kappa_minus_two = in__.scalar_lb_constrain(0, lp__);
            else
                kappa_minus_two = in__.scalar_lb_constrain(0);
            // transformed parameters
            current_statement_begin__ = 72;
            validate_non_negative_index("mu", "L", L);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> mu(L);
            stan::math::initialize(mu, DUMMY_VAR__);
            stan::math::fill(mu, DUMMY_VAR__);
            stan::math::assign(mu,inv_logit(mu_ordered));
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 72;
            size_t mu_j_1_max__ = L;
            for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(mu(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: mu" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable mu: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            check_greater_or_equal(function__, "mu", mu, 0);
            check_less_or_equal(function__, "mu", mu, 1);
            // model body
            {
            current_statement_begin__ = 76;
            local_scalar_t__ log_lik(DUMMY_VAR__);
            (void) log_lik;  // dummy to suppress unused var warning
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            current_statement_begin__ = 78;
            lp_accum__.add(dirichlet_log<propto__>(phi, rep_vector(1, (L * K))));
            current_statement_begin__ = 79;
            lp_accum__.add(gamma_log<propto__>(kappa_minus_two, 0.01, 0.01));
            current_statement_begin__ = 80;
            lp_accum__.add(logistic_log<propto__>(mu_ordered, 0, 1));
            current_statement_begin__ = 82;
            stan::math::assign(log_lik, compute_log_likelihood(N, L, K, x, d, a, mu, kappa_minus_two, v, ref_signatures, phi, pstream__));
            current_statement_begin__ = 84;
            lp_accum__.add(log_lik);
            }
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
        names__.push_back("phi");
        names__.push_back("mu_ordered");
        names__.push_back("kappa_minus_two");
        names__.push_back("mu");
        names__.push_back("log_lik");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back((L * K));
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(L);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(L);
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
        static const char* function__ = "model_signit_model_infer_populations_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> phi = in__.simplex_constrain((L * K));
        size_t phi_j_1_max__ = (L * K);
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            vars__.push_back(phi(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> mu_ordered = in__.ordered_constrain(L);
        size_t mu_ordered_j_1_max__ = L;
        for (size_t j_1__ = 0; j_1__ < mu_ordered_j_1_max__; ++j_1__) {
            vars__.push_back(mu_ordered(j_1__));
        }
        double kappa_minus_two = in__.scalar_lb_constrain(0);
        vars__.push_back(kappa_minus_two);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 72;
            validate_non_negative_index("mu", "L", L);
            Eigen::Matrix<double, Eigen::Dynamic, 1> mu(L);
            stan::math::initialize(mu, DUMMY_VAR__);
            stan::math::fill(mu, DUMMY_VAR__);
            stan::math::assign(mu,inv_logit(mu_ordered));
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 72;
            check_greater_or_equal(function__, "mu", mu, 0);
            check_less_or_equal(function__, "mu", mu, 1);
            // write transformed parameters
            if (include_tparams__) {
                size_t mu_j_1_max__ = L;
                for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
                    vars__.push_back(mu(j_1__));
                }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 88;
            double log_lik;
            (void) log_lik;  // dummy to suppress unused var warning
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // generated quantities statements
            current_statement_begin__ = 90;
            stan::math::assign(log_lik, compute_log_likelihood(N, L, K, x, d, a, mu, kappa_minus_two, v, ref_signatures, phi, pstream__));
            // validate, write generated quantities
            current_statement_begin__ = 88;
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
        return "model_signit_model_infer_populations";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t phi_j_1_max__ = (L * K);
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "phi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t mu_ordered_j_1_max__ = L;
        for (size_t j_1__ = 0; j_1__ < mu_ordered_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu_ordered" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "kappa_minus_two";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t mu_j_1_max__ = L;
            for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "mu" << '.' << j_1__ + 1;
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
        size_t phi_j_1_max__ = ((L * K) - 1);
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "phi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t mu_ordered_j_1_max__ = L;
        for (size_t j_1__ = 0; j_1__ < mu_ordered_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu_ordered" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "kappa_minus_two";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t mu_j_1_max__ = L;
            for (size_t j_1__ = 0; j_1__ < mu_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "mu" << '.' << j_1__ + 1;
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
typedef model_signit_model_infer_populations_namespace::model_signit_model_infer_populations stan_model;
#endif
