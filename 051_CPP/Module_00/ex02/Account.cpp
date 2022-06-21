/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:48:16 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/21 12:14:28 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {
}

Account::Account(int initial_deposit) {
    _accountIndex = Account::getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout<< ";amount:" << initial_deposit;
    std::cout<< ";created" << std::endl;
}

Account::~Account( void ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp() {
    std::time_t cur_timestamp;
    struct tm	tm_struct;
    char		buf[16];

    cur_timestamp = std::time(0);
    tm_struct = *localtime(&cur_timestamp);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tm_struct);
    std::cout << "[" << buf << "] ";
}


void Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << Account::_amount;
    std::cout << ";deposits:" << Account::_nbDeposits;
    std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";p_amount:" << Account::_amount;
    std::cout << ";deposit:" << deposit;
    Account::_amount += deposit;
    Account::_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << ";amount:" << Account::_amount;
    std::cout << ";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex;
    std::cout << ";p_amount:" << Account::_amount;
    std::cout << ";withdrawal:";
    if (Account::_amount - withdrawal < 0)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    else {
        std::cout << withdrawal;
    }
    Account::_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_nbWithdrawals++;
    Account::_totalNbWithdrawals += 1;
    std::cout << ";amount:" << Account::_amount;
    std::cout << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const {
    return (Account::_amount > 0);
}
